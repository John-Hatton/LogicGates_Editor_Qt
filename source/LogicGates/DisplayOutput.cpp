//
// Created by John on 5/27/2024.
//

#include "LogicGates/DisplayOutput.hpp"
#include "Connection.hpp"
#include <QCursor>

DisplayOutput::DisplayOutput() : AbstractNode() {

    DisplayOutput::setNodeName("Display Output");
    setHasInputNode(false);
    setHasOutputNode(true);

    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);        // Apply the brush to the rectangle

    // Add connection points
    inputPoint = new ConnectionPoint(rect().left(), rect().center().y(), 5, ConnectionPoint::Input, this);
    inputPoint->setNode(this);

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

    QPixmap pixmap(":/resources/DisplayOutput.png");
    DisplayOutput::setImage(pixmap);

    // Add small green box on the right side
    rightBox = new QGraphicsRectItem(this);
    rightBox->setRect(rect().width() - 31, (rect().height() / 2) - 10, 25, 25);
    rightBox->setBrush(Qt::black);
}

void DisplayOutput::setNodeName(const QString &name) {
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

void DisplayOutput::setImage(const QPixmap& pixmap) {
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

void DisplayOutput::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    QGraphicsRectItem::mousePressEvent(event);
}

void DisplayOutput::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (dragging) {
        QPointF offset = event->pos() - dragStartPos;
        moveBy(offset.x(), offset.y());
        emit positionChanged(); // Emit the signal when the node moves
    }
    QGraphicsRectItem::mouseMoveEvent(event);
}

void DisplayOutput::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

State DisplayOutput::GetState() const {
    return state_; //
}

void DisplayOutput::Update(State state) {

    if (state == DISABLED)
    {
        rightBox->setBrush(Qt::black);
        if (inputPoint->getConnection())
        {
            auto conn = inputPoint->getConnection();
            conn->setColor(Qt::black);
        }
    }
    if (state == OFF)
    {
        rightBox->setBrush(Qt::red);
        if (inputPoint->getConnection())
        {
            auto conn = inputPoint->getConnection();
            conn->setColor(Qt::red);
        }
    }
    if (state == ON)
    {
        rightBox->setBrush(Qt::green);
        if (inputPoint->getConnection())
        {
            auto conn = inputPoint->getConnection();
            conn->setColor(Qt::green);
        }
    }

    state_ = state;
    Notify();
}

ConnectionPoint* DisplayOutput::getInputPoint() const {
    return inputPoint;
}

ConnectionPoint* DisplayOutput::getOutputPoint() const {
    return nullptr;
}

void DisplayOutput::setInput(AbstractNode *input) {
    input_ = input;
    input_->Attach(this);
    DisplayOutput::Update(input->GetState());
}
