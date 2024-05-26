//
// Created by John on 5/26/2024.
//

#include "LogicGates/PowerSource.hpp"
#include <QCursor>

PowerSource::PowerSource() : AbstractNode() {

    PowerSource::setNodeName("Power Source");
    setHasInputNode(false);
    setHasOutputNode(true);

    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);        // Apply the brush to the rectangle

    // Add connection points
    outputPoint = new ConnectionPoint(rect().right(), rect().center().y(), 5, ConnectionPoint::Output, this);

    // Connect the signals to the editor slots

    // Add text background item
    textBackgroundItem = new QGraphicsRectItem(this);
    textBackgroundItem->setBrush(Qt::black);

    // Add node name item
    nodeNameItem = new QGraphicsTextItem(this);
    nodeNameItem->setDefaultTextColor(Qt::white);
    nodeNameItem->setFont(QFont("Arial", 12));

    // Add image item
    imageItem = new QGraphicsPixmapItem(this);

    QPixmap pixmap(":/resources/PowerSource.png");
    PowerSource::setImage(pixmap);
}

void PowerSource::setNodeName(const QString &name) {
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

void PowerSource::setImage(const QPixmap& pixmap) {
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

void PowerSource::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    QGraphicsRectItem::mousePressEvent(event);
}

void PowerSource::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (dragging) {
        QPointF offset = event->pos() - dragStartPos;
        moveBy(offset.x(), offset.y());
        emit positionChanged(); // Emit the signal when the node moves
    }
    QGraphicsRectItem::mouseMoveEvent(event);
}

void PowerSource::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

State PowerSource::GetState() const {
    return ON; // TODOL Change this later
}

void PowerSource::Update(State state) {
        // do something...
}

ConnectionPoint *PowerSource::getInputPoint() const {
    return nullptr;
}

ConnectionPoint *PowerSource::getOutputPoint() const {
    return outputPoint;
}
