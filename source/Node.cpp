//
// Created by John on 5/24/2024.
//
//
#include <Node.hpp>
#include <QBrush>
#include <QObject>
#include "Editor.hpp"

Node::Node(Editor *editor) : QObject(), QGraphicsRectItem(), dragging(false), editor(editor) {
    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);        // Apply the brush to the rectangle

    // Add connection points
    inputPoint = new ConnectionPoint(rect().left(), rect().center().y(), 5, ConnectionPoint::Input, this);
    outputPoint = new ConnectionPoint(rect().right(), rect().center().y(), 5, ConnectionPoint::Output, this);

    // Connect the signals to the editor slots
    QObject::connect(inputPoint, &ConnectionPoint::connectionStarted, editor, &Editor::startConnection);
    QObject::connect(outputPoint, &ConnectionPoint::connectionStarted, editor, &Editor::startConnection);
    QObject::connect(inputPoint, &ConnectionPoint::connectionUpdated, editor, &Editor::updateConnection);
    QObject::connect(outputPoint, &ConnectionPoint::connectionUpdated, editor, &Editor::updateConnection);
    QObject::connect(inputPoint, &ConnectionPoint::connectionEnded, editor, &Editor::endConnection);
    QObject::connect(outputPoint, &ConnectionPoint::connectionEnded, editor, &Editor::endConnection);
    QObject::connect(inputPoint, &ConnectionPoint::connectionCanceled, editor, &Editor::cancelConnection);
    QObject::connect(outputPoint, &ConnectionPoint::connectionCanceled, editor, &Editor::cancelConnection);
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
        emit positionChanged(); // Emit the signal when the node moves
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
