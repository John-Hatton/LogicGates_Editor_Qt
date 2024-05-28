//
// Created by John on 5/26/2024.
//

#include "LogicGates/PowerSource.hpp"
#include "Connection.hpp"

PowerSource::PowerSource() : AbstractNode() {

    PowerSource::setNodeName("Power Source");
    state_ = DISABLED;
    setHasInputNode(false);
    setHasOutputNode(true);

    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);

    QBrush brush(Qt::blue); // Set the fill color to blue
    setBrush(brush);        // Apply the brush to the rectangle

    // Add connection points
    outputPoint = new ConnectionPoint(rect().right(), rect().center().y(), 5, ConnectionPoint::Output, this);
    outputPoint->setNode(this);

    // Set Image
    QPixmap pixmap(":/resources/PowerSource.png");
    PowerSource::setImage(pixmap);

    // Add small button on the left side
    toggleStateButton = new QGraphicsRectItem(this);
    toggleStateButton->setRect(5, (rect().height() / 2) - 10, 25, 25);
    toggleStateButton->setBrush(Qt::gray);

    // Add text on the button
    toggleStateButtonText = new QGraphicsTextItem("O/I", toggleStateButton);
    toggleStateButtonText->setDefaultTextColor(Qt::white);
    toggleStateButtonText->setFont(QFont("Arial", 8)); // Adjust font size as needed

    // Center the text in the button
    QRectF buttonRect = toggleStateButton->rect();
    QRectF textRect = toggleStateButtonText->boundingRect();
    toggleStateButtonText->setPos(buttonRect.left() + (buttonRect.width() - textRect.width()) / 2,
                           buttonRect.top() + (buttonRect.height() - textRect.height()) / 2);

    // Add small green box on the right side
    stateDisplay = new QGraphicsRectItem(this);
    stateDisplay->setRect(rect().width() - 31, (rect().height() / 2) - 10, 25, 25);
    stateDisplay->setBrush(Qt::black);
}

void PowerSource::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (toggleStateButton->contains(event->pos())) {
            buttonPressed = true;
            updateButtonAppearance(true);
            handleButtonClick(event);
        } else {
            dragging = true;
            dragStartPos = event->pos();
            setCursor(Qt::ClosedHandCursor);
        }
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
    if (buttonPressed) {
        buttonPressed = false;
        updateButtonAppearance(false);
    }

    if (event->button() == Qt::LeftButton) {
        dragging = false;
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void PowerSource::ChangeState(State state) {

    if (state == DISABLED)
    {
        stateDisplay->setBrush(Qt::black);
        if (outputPoint->getConnection())
        {
            auto conn = outputPoint->getConnection();
            conn->setColor(Qt::black);
        }
    }
    if (state == OFF)
    {
        stateDisplay->setBrush(Qt::red);
        if (outputPoint->getConnection())
        {
            auto conn = outputPoint->getConnection();
            conn->setColor(Qt::red);
        }
    }
    if (state == ON)
    {
        stateDisplay->setBrush(Qt::green);
        if (outputPoint->getConnection())
        {
            auto conn = outputPoint->getConnection();
            conn->setColor(Qt::green);
        }
    }

    state_ = state;


    Notify();
}

void PowerSource::ToggleState() {
    if (state_ == DISABLED)
    {
        ChangeState(OFF);
    }
    else if (state_ == OFF)
    {
        ChangeState(ON);
    }
    else if (state_ == ON)
    {
        ChangeState(DISABLED);
    }
}

State PowerSource::GetState() const {
    return state_;
}

void PowerSource::Update(State state) {
    // Do nothing!
    // The switch doesn't have any objects, this is just for show.
}

ConnectionPoint *PowerSource::getOutputXPoint() const {
    return outputPoint;
}


void PowerSource::handleButtonClick(QGraphicsSceneMouseEvent *event) {
    ToggleState();
    qDebug() << "*** - Power Source Button was clicked";
}

void PowerSource::updateButtonAppearance(bool pressed) {
    if (pressed) {
        toggleStateButton->moveBy(1, 1); // Move button slightly down and right
        toggleStateButton->setBrush(Qt::darkGray); // Change color to indicate it's pressed
    } else {
        toggleStateButton->moveBy(-1, -1); // Move button back to original position
        toggleStateButton->setBrush(Qt::gray); // Change color back to original
    }
    // Update text position accordingly
    QRectF buttonRect = toggleStateButton->rect();
    QRectF textRect = toggleStateButtonText->boundingRect();
    toggleStateButtonText->setPos(buttonRect.left() + (buttonRect.width() - textRect.width()) / 2,
                           buttonRect.top() + (buttonRect.height() - textRect.height()) / 2);
}


