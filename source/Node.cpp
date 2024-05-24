//
// Created by John on 5/24/2024.
//
//
//#include "Node.hpp"
//#include <QCursor>
//
//Node::Node() : dragging(false) {
//    setRect(0, 0, 100, 50);
//    setFlag(QGraphicsItem::ItemIsMovable);
//    setFlag(QGraphicsItem::ItemIsSelectable);
//}
//
//void Node::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//    if (event->button() == Qt::LeftButton) {
//        dragging = true;
//        dragStartPos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//    }
//    QGraphicsRectItem::mousePressEvent(event);
//}
//
//void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//    if (dragging) {
//        QPointF offset = event->pos() - dragStartPos;
//        moveBy(offset.x(), offset.y());
//    }
//    QGraphicsRectItem::mouseMoveEvent(event);
//}
//
//void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
//    if (event->button() == Qt::LeftButton) {
//        dragging = false;
//        setCursor(Qt::ArrowCursor);
//    }
//    QGraphicsRectItem::mouseReleaseEvent(event);
//}

//#include "Node.hpp"
//#include <QCursor>
//#include <QDebug> // Add this line
//
//Node::Node() : dragging(false) {
//    setRect(0, 0, 100, 50);
//    setFlag(QGraphicsItem::ItemIsMovable);
//    setFlag(QGraphicsItem::ItemIsSelectable);
//}
//
//void Node::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//    qDebug() << "Node::mousePressEvent - Button:" << event->button() << " Position:" << event->pos();
//
//    if (event->button() == Qt::LeftButton) {
//        dragging = true;
//        dragStartPos = event->pos();
//        setCursor(Qt::ClosedHandCursor);
//        qDebug() << "Node drag started at position:" << dragStartPos;
//    }
//    QGraphicsRectItem::mousePressEvent(event);
//}
//
//void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//    if (dragging) {
//        QPointF offset = event->pos() - dragStartPos;
//        moveBy(offset.x(), offset.y());
//        qDebug() << "Node::mouseMoveEvent - Moving to:" << pos();
//    }
//    QGraphicsRectItem::mouseMoveEvent(event);
//}
//
//void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
//    qDebug() << "Node::mouseReleaseEvent - Button:" << event->button();
//
//    if (event->button() == Qt::LeftButton) {
//        dragging = false;
//        setCursor(Qt::ArrowCursor);
//        qDebug() << "Node drag ended at position:" << pos();
//    }
//    QGraphicsRectItem::mouseReleaseEvent(event);
//}

#include "Node.hpp"
#include <QCursor>
#include <QBrush>

Node::Node() : dragging(false) {
    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);        // Apply the brush to the rectangle
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    QGraphicsRectItem::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (dragging) {
        QPointF offset = event->pos() - dragStartPos;
        moveBy(offset.x(), offset.y());
    }
    QGraphicsRectItem::mouseMoveEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}
