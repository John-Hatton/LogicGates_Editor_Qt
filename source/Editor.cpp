//
// Created by John on 5/24/2024.
//

#include "Editor.hpp"
#include "Node.hpp"
#include "Connection.hpp"
#include <QMouseEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QScrollBar>
#include <QApplication>

Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0), currentConnection(nullptr), startPoint(nullptr), hoveredPoint(nullptr) {
    // Create the scene and set it
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::NoDrag);

    // Set background color
    setBackgroundBrush(QBrush(Qt::darkGray));

    // Create and position the label
    positionLabel = new QLabel(this);
    positionLabel->setFixedWidth(200);
    positionLabel->setStyleSheet("QLabel { color : white; }");
    positionLabel->setText("Initializing...");
    positionLabel->move(10, height() - 30); // Move to bottom-left corner
    positionLabel->show();

    // Set the initial view position to (0,0)
    centerOn(viewCenter);
    updatePositionLabel();
}

void Editor::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    positionLabel->move(10, height() - 30); // Adjust position on resize
}

void Editor::createNode() {
    Node *node = new Node(this);
    scene->addItem(node);
    node->setPos(mapToScene(viewport()->rect().center()));
    connect(node, &Node::positionChanged, this, &Editor::updateConnections);
    qDebug() << "Node created at position:" << node->pos();
}

void Editor::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        isPanning = true;
        panStartPos = event->position();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Editor::mouseMoveEvent(QMouseEvent *event) {
    if (isPanning) {
        QPointF delta = event->position() - panStartPos;
        panStartPos = event->position();
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());  // Invert X axis panning
        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());     // Invert Y axis panning
        viewCenter -= QPointF(-delta.x(), -delta.y()) / scaleFactor;  // Adjust view center accordingly
        updatePositionLabel();
        updateNodesPosition(delta); // Update the position of nodes
        viewport()->update();
        event->accept();
    } else if (currentConnection) {
        QPointF scenePos = mapToScene(event->pos());
        updateConnection(scenePos);

        if (hoveredPoint) {
            hoveredPoint->setBrush(Qt::black);  // Reset color
            hoveredPoint = nullptr;
        }

        for (QGraphicsItem *item : scene->items(scenePos)) {
            if (ConnectionPoint *point = dynamic_cast<ConnectionPoint*>(item)) {
                if (point != startPoint && point->getPointType() != startPoint->getPointType()) {
                    point->setBrush(Qt::green);
                    hoveredPoint = point;
                    break;
                }
            }
        }

        qDebug() << "Drawing connection line to:" << scenePos;
        event->accept();
    } else {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void Editor::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        isPanning = false;
        setCursor(Qt::ArrowCursor);
        qDebug() << "Right mouse button released. Stopping panning.";
        event->accept();
    } else if (event->button() == Qt::LeftButton && currentConnection) {
        if (hoveredPoint) {
            endConnection(hoveredPoint);
        } else {
            cancelConnection();
        }
        event->accept();
    } else {
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void Editor::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        scale(1.1, 1.1);
        scaleFactor *= 1.1;
        qDebug() << "Zooming in. New scale factor:" << scaleFactor;
    } else {
        scale(0.9, 0.9);
        scaleFactor *= 0.9;
        qDebug() << "Zooming out. New scale factor:" << scaleFactor;
    }
    updatePositionLabel();
    updateConnections(); // Update the connections
    viewport()->update();
    event->accept();
}

void Editor::drawBackground(QPainter *painter, const QRectF &rect) {
    QGraphicsView::drawBackground(painter, rect);

    painter->fillRect(rect, Qt::darkGray);

    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(1);

    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % int(20 * scaleFactor));
    qreal top = int(rect.top()) - (int(rect.top()) % int(20 * scaleFactor));

    QVector<QLineF> lines;

    for (qreal x = left; x < rect.right(); x += 20 * scaleFactor) {
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    }
    for (qreal y = top; y < rect.bottom(); y += 20 * scaleFactor) {
        lines.append(QLineF(rect.left(), y, rect.right(), y));
    }

    painter->drawLines(lines.data(), lines.size());

    // Draw the origin
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawEllipse(viewCenter, 5, 5); // Draw the origin at the view center
}

void Editor::updatePositionLabel() {
    qDebug() << "Updating position label. View center:" << viewCenter << "Scale factor:" << scaleFactor;
    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()*-1).arg(viewCenter.y()).arg(scaleFactor));
    // Redraw the background to reflect the new position
    viewport()->update();
}

void Editor::updateConnections() {
    for (Connection *connection : connections) {
        connection->update();
    }
}

void Editor::updateNodesPosition(const QPointF &delta) {
    for (QGraphicsItem *item : scene->items()) {
        if (Node *node = dynamic_cast<Node*>(item)) {
            node->moveBy(delta.x(), delta.y());
        }
    }

    updateConnections();
}

void Editor::startConnection(ConnectionPoint *point) {
    if (currentConnection == nullptr) {
        startPoint = point;
        currentConnection = new QGraphicsLineItem(QLineF(point->getScenePosition(), point->getScenePosition()));
        QPen pen;
        pen.setWidth(2); // Adjust this value to make the line thicker or thinner
        currentConnection->setPen(pen);
        scene->addItem(currentConnection);
        qDebug() << "Started connection from point:" << point->toString();
    }
}

void Editor::updateConnection(const QPointF &pos) {
    if (currentConnection) {
        QLineF newLine(currentConnection->line().p1(), pos);
        currentConnection->setLine(newLine);
        qDebug() << "Updated connection to:" << pos;
    }
}

void Editor::endConnection(ConnectionPoint *point) {
    if (currentConnection && hoveredPoint && hoveredPoint != startPoint && hoveredPoint->getPointType() != startPoint->getPointType()) {
        QLineF newLine = currentConnection->line();
        newLine.setP2(hoveredPoint->getScenePosition());
        currentConnection->setLine(newLine);
        finalizeConnection(startPoint, hoveredPoint);
        currentConnection = nullptr;
        startPoint = nullptr;
        qDebug() << "Ended connection at point:" << point->toString();

        if (hoveredPoint) {
            hoveredPoint->setBrush(Qt::black); // Reset color
            hoveredPoint = nullptr;
        }
    } else {
        cancelConnection();  // Cancel the connection if it wasn't valid
    }
}

void Editor::cancelConnection() {
    if (currentConnection) {
        scene->removeItem(currentConnection);
        delete currentConnection;
        currentConnection = nullptr;
        startPoint = nullptr;
        qDebug() << "Connection canceled.";

        if (hoveredPoint) {
            hoveredPoint->setBrush(Qt::black); // Reset color
            hoveredPoint = nullptr;
        }
    }
}

void Editor::finalizeConnection(ConnectionPoint *start, ConnectionPoint *end) {
    // Create a new connection and add it to the collection
    Connection *connection = new Connection(start, end, scene);
    connections.push_back(connection);
    qDebug() << "Finalized connection from" << start->toString() << "to" << end->toString();
    // Remove the temporary connection line
    scene->removeItem(currentConnection);
    delete currentConnection;
    currentConnection = nullptr;
}

void Editor::newFile() {
    // Clear the scene
    scene->clear();
    connections.clear();
    qDebug() << "New file created.";
}

void Editor::newCanvas() {
    scene->clear();
    connections.clear();
    qDebug() << "New canvas created.";
}

void Editor::exitApp() {
    QApplication::quit();
}
