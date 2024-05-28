//
// Created by John on 5/27/2024.
//

#include "LogicGates/DisplayOutput.hpp"
#include "Connection.hpp"


DisplayOutput::DisplayOutput() : AbstractNode() {

    DisplayOutput::setNodeName("Display Output");
    setHasInputNode(true);
    setHasOutputNode(false);

    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);        // Apply the brush to the rectangle

    // Add connection points
    inputPoint = new ConnectionPoint(rect().left(), rect().center().y(), 5, ConnectionPoint::Input, this);
    inputPoint->setNode(this);

    // Set image
    QPixmap pixmap(":/resources/DisplayOutput.png");
    DisplayOutput::setImage(pixmap);

    // Add small green box on the right side
    stateDisplay = new QGraphicsRectItem(this);
    stateDisplay->setRect(rect().width() - 31, (rect().height() / 2) - 10, 25, 25);
    stateDisplay->setBrush(Qt::black);
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
    return state_;
}

void DisplayOutput::setInput(AbstractNode *input) {
    input_ = input;
    input_->Attach(this);
    DisplayOutput::Update(input->GetState());
}

void DisplayOutput::Update(State state) {

    if (state == DISABLED)
    {
        stateDisplay->setBrush(Qt::black);
        if (inputPoint->getConnection())
        {
            auto conn = inputPoint->getConnection();
            conn->setColor(Qt::black);
        }
    }
    if (state == OFF)
    {
        stateDisplay->setBrush(Qt::red);
        if (inputPoint->getConnection())
        {
            auto conn = inputPoint->getConnection();
            conn->setColor(Qt::red);
        }
    }
    if (state == ON)
    {
        stateDisplay->setBrush(Qt::green);
        if (inputPoint->getConnection())
        {
            auto conn = inputPoint->getConnection();
            conn->setColor(Qt::green);
        }
    }

    state_ = state;
    Notify();
}

ConnectionPoint *DisplayOutput::getInputXPoint() const {
    return inputPoint;
}


