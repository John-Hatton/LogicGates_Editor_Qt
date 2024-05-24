//
// Created by John on 5/24/2024.
//

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug> // Add this line
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::RubberBandDrag);
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    qDebug() << "Editor::mousePressEvent - Button:" << event->button() << " Position:" << event->pos();
//
//    if (event->button() == Qt::RightButton) {
//        Node *node = new Node();
//        scene->addItem(node);
//        node->setPos(mapToScene(event->pos()));
//        qDebug() << "Node created at position:" << node->pos();
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QPainter>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::ScrollHandDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set up layout with the menu bar
//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->setMenuBar(menuBar);
//    layout->addWidget(this);
//    parent->setLayout(layout);
//
//    // Set the initial scale factor
//    scaleFactor = 1.0;
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    scene->update();
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
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::ScrollHandDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set the initial scale factor
//    scaleFactor = 1.0;
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    scene->update();
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
//}


//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, 10);
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    scene->update();
//    updatePositionLabel();
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
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Position: [%1, %2]").arg(scenePos.x()).arg(scenePos.y()));
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), origin(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(origin);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5);
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Position: [%1, %2], Zoom: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), origin(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(origin);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5);
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Position: [%1, %2], Zoom: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5);
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Position: [%1, %2], Zoom: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//


//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        QPointF newCenter = mapToScene(viewport()->rect().center()) - delta;
//        centerOn(newCenter);
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    QPointF originScenePos = mapToScene(viewport()->rect().center());
//    painter->drawEllipse(originScenePos, 5, 5);
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Position: [%1, %2], Zoom: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}
//
//void Editor::setMenuBar(QMenuBar *menuBar) {
//    Editor::menuBar = menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(QPointF(0, 0), 5, 5); // Always draw the origin at (0, 0)
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Position: [%1, %2], Zoom: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        lastMousePos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        QPoint delta = event->pos() - lastMousePos;
//        lastMousePos = event->pos();
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
//    } else {
//        QGraphicsView::mouseMoveEvent(event);
//    }
//}
//
//void Editor::mouseReleaseEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = false;
//        setCursor(Qt::ArrowCursor);
//    } else {
//        QGraphicsView::mouseReleaseEvent(event);
//    }
//}
//
//void Editor::wheelEvent(QWheelEvent *event) {
//    if (event->angleDelta().y() > 0) {
//        scale(1.1, 1.1);
//        scaleFactor *= 1.1;
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//
//    }
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartX = event->x();
//        panStartY = event->y();
//        setCursor(Qt::ClosedHandCursor);
//        event->accept();
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - panStartX));
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - panStartY));
//        panStartX = event->x();
//        panStartY = event->y();
//        updatePositionLabel();
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
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(QPointF(0, 0), 5, 5); // Always draw the origin at (0, 0)
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : white; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartX = event->x();
//        panStartY = event->y();
//        setCursor(Qt::ClosedHandCursor);
//        event->accept();
//    } else {
//        QGraphicsView::mousePressEvent(event);
//    }
//}
//
//void Editor::mouseMoveEvent(QMouseEvent *event) {
//    if (isPanning) {
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - panStartX));
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - panStartY));
//        panStartX = event->x();
//        panStartY = event->y();
//        updatePositionLabel();
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
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5); // Draw the origin at the center of the view
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
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
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
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
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5); // Draw the origin at the center of the view
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
//    positionLabel->setText("Initializing...");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
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
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
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
//    } else {
//        scale(0.9, 0.9);
//        scaleFactor *= 0.9;
//    }
//    updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5); // Draw the origin at the center of the view
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    qDebug() << "Updating position label:" << scenePos << scaleFactor;
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
//    positionLabel->setText("Initializing...");
//    positionLabel->move(10, height() - 30); // Move to bottom-left corner
//    positionLabel->show();
//
//    // Set the initial view position to (0,0)
//    centerOn(0, 0);
//    updatePositionLabel();
//}
//
//void Editor::resizeEvent(QResizeEvent *event) {
//    QGraphicsView::resizeEvent(event);
//    positionLabel->move(10, height() - 30); // Adjust position on resize
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//    updatePositionLabel();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
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
//        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        updatePositionLabel();
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
//    painter->drawEllipse(mapToScene(viewport()->rect().center()), 5, 5); // Draw the origin at the center of the view
//}
//
//void Editor::updatePositionLabel() {
//    QPointF scenePos = mapToScene(viewport()->rect().center());
//    qDebug() << "Updating position label:" << scenePos << scaleFactor;
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(scenePos.x()).arg(scenePos.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}


//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
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
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//    updatePositionLabel();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
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
//        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        viewCenter += delta / scaleFactor;  // Update view center based on delta and scale
//        updatePositionLabel();
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
//    painter->drawEllipse(QPointF(0, 0), 5, 5); // Draw the origin at (0, 0)
//}
//
//void Editor::updatePositionLabel() {
//    qDebug() << "Updating position label. View center:" << viewCenter << "Scale factor:" << scaleFactor;
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()).arg(viewCenter.y()).arg(scaleFactor));
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
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
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//    updatePositionLabel();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
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
//        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        viewCenter -= delta / scaleFactor;  // Update view center based on delta and scale
//        updatePositionLabel();
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
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()).arg(viewCenter.y()).arg(scaleFactor));
//    // Redraw the background to reflect the new position
//    scene->update(sceneRect());
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
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
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//    updatePositionLabel();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
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
//        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        viewCenter -= delta / scaleFactor;  // Update view center based on delta and scale
//        updatePositionLabel();
//        viewport()->update();
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
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()).arg(viewCenter.y()).arg(scaleFactor));
//    // Redraw the background to reflect the new position
//    viewport()->update();
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}

//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
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
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//    updatePositionLabel();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
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
//        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());  // Invert X axis panning
//        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
//        viewCenter -= QPointF(-delta.x(), delta.y()) / scaleFactor;  // Adjust view center accordingly
//        updatePositionLabel();
//        viewport()->update();
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
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()).arg(viewCenter.y()).arg(scaleFactor));
//    // Redraw the background to reflect the new position
//    viewport()->update();
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}
//


//#include "Editor.hpp"
//#include "Node.hpp"
//#include <QMouseEvent>
//#include <QDebug>
//#include <QVBoxLayout>
//#include <QWheelEvent>
//#include <QGraphicsRectItem>
//#include <QLabel>
//#include <QScrollBar>
//
//Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0) {
//    // Create the scene and set it
//    setScene(scene);
//    setRenderHint(QPainter::Antialiasing);
//    setDragMode(QGraphicsView::NoDrag);
//
//    // Create the menu bar
//    menuBar = new QMenuBar(this);
//    QMenu *nodesMenu = menuBar->addMenu("Nodes");
//
//    // Create the "New Node" action
//    newNodeAction = new QAction("New Node", this);
//    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
//    nodesMenu->addAction(newNodeAction);
//
//    // Set background color
//    setBackgroundBrush(QBrush(Qt::darkGray));
//
//    // Create and position the label
//    positionLabel = new QLabel(this);
//    positionLabel->setStyleSheet("QLabel { color : black; }");
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
//    updatePositionLabel();
//}
//
//void Editor::createNode() {
//    Node *node = new Node();
//    scene->addItem(node);
//    node->setPos(mapToScene(viewport()->rect().center()));
//    qDebug() << "Node created at position:" << node->pos();
//    updatePositionLabel();
//}
//
//void Editor::mousePressEvent(QMouseEvent *event) {
//    if (event->button() == Qt::RightButton) {
//        isPanning = true;
//        panStartPos = event->position();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
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
//        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());  // Invert X axis panning
//        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());     // Invert Y axis panning
//        viewCenter -= QPointF(-delta.x(), -delta.y()) / scaleFactor;  // Adjust view center accordingly
//        updatePositionLabel();
//        viewport()->update();
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
//    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()).arg(viewCenter.y()).arg(scaleFactor));
//    // Redraw the background to reflect the new position
//    viewport()->update();
//}
//
//QMenuBar *Editor::getMenuBar() const {
//    return menuBar;
//}


#include "Editor.hpp"
#include "Node.hpp"
#include <QMouseEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QWheelEvent>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QScrollBar>

Editor::Editor(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)), scaleFactor(1.0), isPanning(false), viewCenter(0, 0) {
    // Create the scene and set it
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::NoDrag);

    // Create the menu bar
    menuBar = new QMenuBar(this);
    QMenu *nodesMenu = menuBar->addMenu("Nodes");

    // Create the "New Node" action
    newNodeAction = new QAction("New Node", this);
    connect(newNodeAction, &QAction::triggered, this, &Editor::createNode);
    nodesMenu->addAction(newNodeAction);

    // Set background color
    setBackgroundBrush(QBrush(Qt::darkGray));

    // Create and position the label
    positionLabel = new QLabel(this);
    positionLabel->setStyleSheet("QLabel { color : black; }");
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
    updatePositionLabel();
}

void Editor::createNode() {
    Node *node = new Node();
    scene->addItem(node);
    node->setPos(mapToScene(viewport()->rect().center()) - viewCenter);
    qDebug() << "Node created at position:" << node->pos();
    updatePositionLabel();
}

void Editor::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        isPanning = true;
        panStartPos = event->position();
        setCursor(Qt::ClosedHandCursor);
        qDebug() << "Right mouse button pressed. Starting panning at:" << panStartPos;
        event->accept();
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Editor::mouseMoveEvent(QMouseEvent *event) {
    if (isPanning) {
        QPointF delta = event->position() - panStartPos;
        panStartPos = event->position();
        qDebug() << "Panning... Delta:" << delta << "New pan start position:" << panStartPos;
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());  // Invert X axis panning
        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());     // Invert Y axis panning
        viewCenter -= QPointF(-delta.x(), -delta.y()) / scaleFactor;  // Adjust view center accordingly
        updatePositionLabel();
        updateNodesPosition(delta); // Update the position of nodes
        viewport()->update();
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
    positionLabel->setText(QString("Pos: x: %1, y: %2, z: %3").arg(viewCenter.x()).arg(viewCenter.y()).arg(scaleFactor));
    // Redraw the background to reflect the new position
    viewport()->update();
}

void Editor::updateNodesPosition(const QPointF &delta) {
    for (QGraphicsItem *item : scene->items()) {
        if (Node *node = dynamic_cast<Node*>(item)) {
            node->moveBy(delta.x(), delta.y());
        }
    }
}

QMenuBar *Editor::getMenuBar() const {
    return menuBar;
}
