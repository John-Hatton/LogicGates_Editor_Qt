//
// Created by John on 5/24/2024.
//

#include <Node.hpp>
#include <QBrush>
#include <QObject>
#include "Editor.hpp"

#include <Node.hpp>
#include <QBrush>
#include <QObject>
#include <QFont>
#include <QDebug>
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

    // Add text background item
    textBackgroundItem = new QGraphicsRectItem(this);
    textBackgroundItem->setBrush(Qt::black);

    // Add node name item
    nodeNameItem = new QGraphicsTextItem(this);
    nodeNameItem->setDefaultTextColor(Qt::white);
    nodeNameItem->setFont(QFont("Arial", 12));

    // Add image item
    imageItem = new QGraphicsPixmapItem(this);

    // Add small button on the left side
    leftButton = new QGraphicsRectItem(this);
    leftButton->setRect(-10, (rect().height() / 2) - 5, 10, 10);
    leftButton->setBrush(Qt::gray);

    // Add small green box on the right side
    rightBox = new QGraphicsRectItem(this);
    rightBox->setRect(rect().width(), (rect().height() / 2) - 5, 10, 10);
    rightBox->setBrush(Qt::green);
}

void Node::setNodeName(const QString &name) {
    nodeNameItem->setPlainText(name);
    // Calculate the position for the text background
    QRectF textRect = nodeNameItem->boundingRect();
    qreal backgroundWidth = textRect.width() + 6; // Reduced padding
    qreal backgroundHeight = textRect.height() - 2; // Reduced height
    textBackgroundItem->setRect(0, 0, backgroundWidth, backgroundHeight);

    // Center the text and background
    qreal xPos = rect().center().x() - backgroundWidth / 2;
    qreal yPos = rect().top() - backgroundHeight / 2; // Center it on the top border

    textBackgroundItem->setPos(xPos, yPos);
    nodeNameItem->setPos(xPos + 3, yPos); // Add padding for the text inside the background
}

void Node::setImage(const QPixmap& pixmap) {
    if (!pixmap.isNull()) {
        QPixmap scaledPixmap = pixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Adjust size as needed
        imageItem->setPixmap(scaledPixmap);
        // Calculate the center position of the node and adjust for the scaled image size
        qreal xPos = (rect().width() - scaledPixmap.width()) / 2;
        qreal yPos = (rect().height() - scaledPixmap.height()) / 2 + 5;
        imageItem->setPos(xPos, yPos);
        qDebug() << "Image set successfully.";
    } else {
        qDebug() << "Failed to load image.";
    }
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
