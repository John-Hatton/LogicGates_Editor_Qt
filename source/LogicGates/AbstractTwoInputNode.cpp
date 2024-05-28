//
// Created by John on 5/27/2024.
//

#include "LogicGates/AbstractTwoInputNode.hpp"

AbstractTwoInputNode::AbstractTwoInputNode() {
    setHasInputNode(true);
    setHasOutputNode(true);
    setHasTwoInputNodes(true);

    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);

    inputPointX = new ConnectionPoint(rect().left(), rect().center().y() - 10, 5, ConnectionPoint::Input, this);
    inputPointX->setNode(this);
    inputPointY = new ConnectionPoint(rect().left(), rect().center().y() + 10, 5, ConnectionPoint::Input, this);
    inputPointY->setNode(this);
    outputPoint = new ConnectionPoint(rect().right(), rect().center().y(), 5, ConnectionPoint::Input, this);
    outputPoint->setNode(this);

    outputPoint = new ConnectionPoint(rect().right(), rect().center().y(), 5, ConnectionPoint::Output, this);
    outputPoint->setNode(this);

    // Image should be set in subclass constructors.

    inputX = nullptr;
    inputY = nullptr;
    outputState_ = DISABLED;
    connectedNodes_ = {};
}

void AbstractTwoInputNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    QGraphicsRectItem::mousePressEvent(event);
}

void AbstractTwoInputNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (dragging) {
        QPointF offset = event->pos() - dragStartPos;
        moveBy(offset.x(), offset.y());
        emit positionChanged(); // Emit the signal when the node moves
    }
    QGraphicsRectItem::mouseMoveEvent(event);
}

void AbstractTwoInputNode::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragging = false;
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void AbstractTwoInputNode::setInputX(AbstractNode *input) {
    inputX = input;
    input->Attach(this);
    connectedNodes_.push_back(inputX);
    AbstractTwoInputNode::Update(GetState());
}

void AbstractTwoInputNode::setInputY(AbstractNode *input) {
    inputY = input;
    input->Attach(this);
    connectedNodes_.push_back(inputY);
    AbstractTwoInputNode::Update(GetState());
}

void AbstractTwoInputNode::removeInputX() {
    inputX->Detach(this);
    connectedNodes_.remove(inputX);
    inputX = nullptr;
}

void AbstractTwoInputNode::removeInputY() {
    inputY->Detach(this);
    connectedNodes_.remove(inputY);
    inputY = nullptr;
}

void AbstractTwoInputNode::Update(State state) {
    outputState_ = state;
    Notify();
}

ConnectionPoint *AbstractTwoInputNode::getInputXPoint() const {
    return inputPointX;
}

ConnectionPoint *AbstractTwoInputNode::getInputYPoint() const {
    return inputPointY;
}

ConnectionPoint *AbstractTwoInputNode::getOutputXPoint() const {
    return outputPoint;
}