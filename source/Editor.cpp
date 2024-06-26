//
// Created by John on 5/24/2024.
//

//#include <Editor.hpp>
//#include <Node.hpp>
//#include <Connection.hpp>
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//#include <QApplication>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0), currentConnection(nullptr), startPoint(nullptr), hoveredPoint(nullptr) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setFixedWidth(200);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->setText("Initializing...");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(viewCenter);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node(this);
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    connect(node, &Node::positionChanged, this, &Editor::updateConnections);
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        event->accept();
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPointF delta = event->position() - panStartPos;
//        panStartPos = event->position();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());  // Invert X axis panning
//        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());     // Invert Y axis panning
//        viewCenter -= QPointF(-delta.x(), -delta.y()) / scaleFactor;  // Adjust view center accordingly
//        updatePositionLabel();
//        updateNodesPosition(delta); // Update the position of nodes
//        viewport()->update();
//        event->accept();
//    } else if (currentConnection) {
//        QPointF scenePos = mapToScene(event->pos());
//        updateConnection(scenePos);
//
//        if (hoveredPoint) {
//            hoveredPoint->setBrush(Qt::black);  // Reset color
//            hoveredPoint = nullptr;
//        }
//
//        for (QGraphicsItem *item : scene->items(scenePos)) {
//            if (ConnectionPoint *point = dynamic_cast<ConnectionPoint*>(item)) {
//                if (point != startPoint && point->getPointType() != startPoint->getPointType()) {
//                    point->setBrush(Qt::green);
//                    hoveredPoint = point;
//                    break;
//                }
//            }
//        }
//
//        qDebug() << "Drawing connection line to:" << scenePos;
//        event->accept();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//        qDebug() << "Right mouse button released. Stopping panning.";
//        event->accept();
//    } else if (event->button() == Qt::LeftButton && currentConnection) {
//        if (hoveredPoint) {
//            endConnection(hoveredPoint);
//        } else {
//            cancelConnection();
//        }
//        event->accept();
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//        qDebug() << "Zooming in. New scale factor:" << scaleFactor;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//        qDebug() << "Zooming out. New scale factor:" << scaleFactor;
//    }
//    updatePositionLabel();
//    updateConnections(); // Update the connections
//    viewport()->update();
//    event->accept();
//}
//
//void Editor::drawBackground(QPainter *painter, const QRectF &rect) {
//    QGraphicsView::drawBackground(painter, rect);
//
//    painter->fillRect(rect, Qt::darkGray);
//
//    QPen pen;
//    pen.setColor(Qt::white);
//    pen.setWidth(1);
//
//    painter->setPen(pen);
//
//    qreal left = int(rect.left()) - (int(rect.left()) % int(20 * scaleFactor));
//    qreal top = int(rect.top()) - (int(rect.top()) % int(20 * scaleFactor));
//
//    QVector<QLineF> lines;
//
//    for (qreal x = left; x < rect.right(); x += 20 * scaleFactor) {
//        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
//    }
//    for (qreal y = top; y < rect.bottom(); y += 20 * scaleFactor) {
//        lines.append(QLineF(rect.left(), y, rect.right(), y));
//    }
//
//    painter->drawLines(lines.data(), lines.size());
//
//    // Draw the origin
//    pen.setColor(Qt::red);
//    pen.setWidth(2);
//    painter->setPen(pen);
//    painter->drawEllipse(viewCenter, 5, 5); // Draw the origin at the view center
//}
//
//void Editor::updatePositionLabel() {
//    qDebug() << "Updating position label. View center:" << viewCenter << "Scale factor:" << scaleFactor;
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()*-1).arg(viewCenter.y()).arg(scaleFactor));
//    // Redraw the background to reflect the new position
//    viewport()->update();
//}
//
//void Editor::updateConnections() {
//    for (Connection *connection : connections) {
//        connection->update();
//    }
//}
//
//void Editor::updateNodesPosition(const QPointF &delta) {
//    for (QGraphicsItem *item : scene->items()) {
//        if (Node *node = dynamic_cast<Node*>(item)) {
//            node->moveBy(delta.x(), delta.y());
//        }
//    }
//
//    updateConnections();
//}
//
//void Editor::startConnection(ConnectionPoint *point) {
//    if (currentConnection == nullptr) {
//        startPoint = point;
//        currentConnection = new QGraphicsLineItem(QLineF(point->getScenePosition(), point->getScenePosition()));
//        QPen pen;
//        pen.setWidth(2); // Adjust this value to make the line thicker or thinner
//        currentConnection->setPen(pen);
//        scene->addItem(currentConnection);
//        qDebug() << "Started connection from point:" << point->toString();
//    }
//}
//
//void Editor::updateConnection(const QPointF &pos) {
//    if (currentConnection) {
//        QLineF newLine(currentConnection->line().p1(), pos);
//        currentConnection->setLine(newLine);
//        qDebug() << "Updated connection to:" << pos;
//    }
//}
//
//void Editor::endConnection(ConnectionPoint *point) {
//    if (currentConnection && hoveredPoint && hoveredPoint != startPoint && hoveredPoint->getPointType() != startPoint->getPointType()) {
//        QLineF newLine = currentConnection->line();
//        newLine.setP2(hoveredPoint->getScenePosition());
//        currentConnection->setLine(newLine);
//        finalizeConnection(startPoint, hoveredPoint);
//        currentConnection = nullptr;
//        startPoint = nullptr;
//        qDebug() << "Ended connection at point:" << point->toString();
//
//        if (hoveredPoint) {
//            hoveredPoint->setBrush(Qt::black); // Reset color
//            hoveredPoint = nullptr;
//        }
//    } else {
//        cancelConnection();  // Cancel the connection if it wasn't valid
//    }
//}
//
//void Editor::cancelConnection() {
//    if (currentConnection) {
//        scene->removeItem(currentConnection);
//        delete currentConnection;
//        currentConnection = nullptr;
//        startPoint = nullptr;
//        qDebug() << "Connection canceled.";
//
//        if (hoveredPoint) {
//            hoveredPoint->setBrush(Qt::black); // Reset color
//            hoveredPoint = nullptr;
//        }
//    }
//}
//
//void Editor::finalizeConnection(ConnectionPoint *start, ConnectionPoint *end) {
//    // Create a new connection and add it to the collection
//    Connection *connection = new Connection(start, end, scene);
//    connections.push_back(connection);
//    qDebug() << "Finalized connection from" << start->toString() << "to" << end->toString();
//    // Remove the temporary connection line
//    scene->removeItem(currentConnection);
//    delete currentConnection;
//    currentConnection = nullptr;
//}
//
//void Editor::newFile() {
//    // Clear the scene
//    scene->clear();
//    connections.clear();
//    qDebug() << "New file created.";
//}
//
//void Editor::newCanvas() {
//    scene->clear();
//    connections.clear();
//    qDebug() << "New canvas created.";
//}
//
//void Editor::exitApp() {
//    QApplication::quit();
//}


#include <Editor.hpp>
#include <Node.hpp>
#include <Connection.hpp>
#include <QMouseEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QScrollBar>
#include <QApplication>
#include <QUndoStack>
#include <QUndoCommand>
#include "AbstractNode.hpp"
#include "LogicGates/DisplayOutput.hpp"
#include "LogicGates/AbstractTwoInputNode.hpp"

Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0), currentConnection(nullptr), startPoint(nullptr), hoveredPoint(nullptr), lastHoveredPoint(nullptr){
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

void Editor::createNode(AbstractNode* abstractNode) {

    //Node *node = new Node(this);
    AbstractNode* node = abstractNode;

    if (node->getHasInputNode())
    {

        if (node->getHasTwoInputNodes())
        {
            if (node->getInputXPoint())
            {
                QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
                QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
                QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
                QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
            }
            if (node->getInputYPoint())
            {
                QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
                QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
                QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
                QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
            }
        }
        if (node->getHasOutputNode())
        {
            if (node->getHasTwoInputTwoOutput())
            {
                // Full Adder, etc. case
                if (node->getInputXPoint())
                {
                    QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
                    QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
                    QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
                    QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
                }
                if (node->getInputYPoint())
                {
                    QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
                    QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
                    QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
                    QObject::connect(node->getInputYPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
                }
                if (node->getOutputXPoint())
                {
                    QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
                    QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
                    QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
                    QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
                }
                if (node->getOutputYPoint())
                {
                    QObject::connect(node->getOutputYPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
                    QObject::connect(node->getOutputYPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
                    QObject::connect(node->getOutputYPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
                    QObject::connect(node->getOutputYPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
                }
            }
        }
        QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
        QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
        QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
        QObject::connect(node->getInputXPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
    }
    if (node->getHasOutputNode())
    {
        QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionStarted, this, &Editor::startConnection);
        QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionUpdated, this, &Editor::updateConnection);
        QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionEnded, this, &Editor::endConnection);
        QObject::connect(node->getOutputXPoint(), &ConnectionPoint::connectionCanceled, this, &Editor::cancelConnection);
    }

    scene->addItem(node);
    node->setPos(mapToScene(viewport()->rect().center()));

    connect(node, &AbstractNode::positionChanged, this, &Editor::updateConnections);
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
                    if (point->getPointType() == ConnectionPoint::Input && point->isConnected()) {
                        point->setBrush(Qt::red); // Input already connected
                    } else {
                        point->setBrush(Qt::green);
                        hoveredPoint = point;
                    }
                    lastHoveredPoint = point;
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
        if (hoveredPoint && !(hoveredPoint->getPointType() == ConnectionPoint::Input && hoveredPoint->isConnected())) {
            endConnection(hoveredPoint);
        } else {
            cancelConnection();
        }
        if (lastHoveredPoint) { // Reset the color of the last hovered point
            lastHoveredPoint->setBrush(Qt::black);
            lastHoveredPoint = nullptr;
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
    for (QGraphicsItem* item : scene->items()) {
        if (auto node = dynamic_cast<AbstractNode*>(item)) {
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
    auto connection = new Connection(start, end, scene);
    start->setConnection(connection);
    end->setConnection(connection);
    if (auto node = dynamic_cast<DisplayOutput*>(end->getNode()))
    {
        node->setInput(start->getNode());
    }
    if (auto node = dynamic_cast<AbstractTwoInputNode*>(end->getNode()))
    {
        if (end == node->getInputXPoint())
        {
            node->setInputX(start->getNode());
        }
        if (end == node->getInputYPoint())
        {
            node->setInputY(start->getNode());
        }

    }

    if (start->getPointType() == ConnectionPoint::Input)
    {
        if (auto node = dynamic_cast<DisplayOutput*>(start->getNode()))
        {
            node->setInput(end->getNode());
        }
        if (auto node = dynamic_cast<AbstractTwoInputNode*>(start->getNode()))
        {
            if (start == node->getInputXPoint())
            {
                node->setInputX(end->getNode());
            }
            if (start == node->getInputYPoint())
            {
                node->setInputY(end->getNode());
            }

        }
    }
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

//void Editor::keyPressEvent(QKeyEvent *event) {
//    if (event->key() == Qt::Key_Delete) {
//        QList<QGraphicsItem*> selectedItems = scene->selectedItems();
//        for (QGraphicsItem* item : selectedItems) {
//            if (auto node = dynamic_cast<AbstractNode*>(item)) {
//                // Remove connections associated with the node
//                for (auto connection : connections) {
//                    if (connection->getStartPoint()->getNode() == node || connection->getEndPoint()->getNode() == node) {
//                        scene->removeItem(connection);
//                        delete connection;
//                    }
//                }
//                connections.erase(std::remove_if(connections.begin(), connections.end(),
//                                                 [node](Connection* connection) {
//                                                     return connection->getStartPoint()->getNode() == node ||
//                                                            connection->getEndPoint()->getNode() == node;
//                                                 }),
//                                  connections.end());
//
//                scene->removeItem(node);
//                qDebug() << "Node deleted:" << node->toString();
//                delete node;
//
//            }
//        }
//    } else {
//        QGraphicsView::keyPressEvent(event);
//    }
//}
void Editor::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        QList<QGraphicsItem*> selectedItems = scene->selectedItems();
        std::vector<Connection*> connectionsToDelete; // To collect connections to delete

        for (QGraphicsItem* item : selectedItems) {
            if (auto node = dynamic_cast<AbstractNode*>(item)) {
                // Collect connections associated with the node
                for (auto connection : connections) {
                    if (connection->getStartPoint()->getNode() == node || connection->getEndPoint()->getNode() == node) {
                        connectionsToDelete.push_back(connection);
                    }
                }

                if (node->getOutputXPoint()->isConnected())
                {
                    // Set the not deleted node's state to disabled
                    node->getOutputXPoint()->getConnection()->getEndPoint()->getNode()->Update(DISABLED);
                    // Reset EndPoint of Connection
                    node->getOutputXPoint()->getConnection()->getEndPoint()->resetConnection();
                    // Reset StartPoint of Connection
                    node->getOutputXPoint()->resetConnection();

                }

                scene->removeItem(node);
                qDebug() << "Node deleted:" << node->toString();
                delete node;
            }
        }

        // Delete the collected connections
        for (auto connection : connectionsToDelete) {
            scene->removeItem(connection);
            delete connection;
        }

        // Erase deleted connections from the main list
        connections.erase(std::remove_if(connections.begin(), connections.end(),
                                         [&connectionsToDelete](Connection* connection) {
                                             return std::find(connectionsToDelete.begin(), connectionsToDelete.end(), connection) != connectionsToDelete.end();
                                         }),
                          connections.end());
    } else {
        QGraphicsView::keyPressEvent(event);
    }
}
