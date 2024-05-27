//
// Created by John on 5/26/2024.
//

#include "LogicGates/PowerSource.hpp"
#include "Connection.hpp"
#include <QCursor>

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

    // Add small button on the left side
    leftButton = new QGraphicsRectItem(this);
    leftButton->setRect(5, (rect().height() / 2) - 10, 25, 25);
    leftButton->setBrush(Qt::gray);

    // Add text on the button
    leftButtonText = new QGraphicsTextItem("O/I", leftButton);
    leftButtonText->setDefaultTextColor(Qt::white);
    leftButtonText->setFont(QFont("Arial", 8)); // Adjust font size as needed

    // Center the text in the button
    QRectF buttonRect = leftButton->rect();
    QRectF textRect = leftButtonText->boundingRect();
    leftButtonText->setPos(buttonRect.left() + (buttonRect.width() - textRect.width()) / 2,
                           buttonRect.top() + (buttonRect.height() - textRect.height()) / 2);

    // Add small green box on the right side
    rightBox = new QGraphicsRectItem(this);
    rightBox->setRect(rect().width() - 31, (rect().height() / 2) - 10, 25, 25);
    rightBox->setBrush(Qt::black);
}

void PowerSource::setNodeName(const QString &name) {
    nodeName = name;
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
        if (leftButton->contains(event->pos())) {
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
        rightBox->setBrush(Qt::black);
        if (outputPoint->getConnection())
        {
            auto conn = outputPoint->getConnection();
            conn->setColor(Qt::black);
        }
    }
    if (state == OFF)
    {
        rightBox->setBrush(Qt::red);
        if (outputPoint->getConnection())
        {
            auto conn = outputPoint->getConnection();
            conn->setColor(Qt::red);
        }
    }
    if (state == ON)
    {
        rightBox->setBrush(Qt::green);
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

ConnectionPoint *PowerSource::getInputPoint() const {
    return nullptr;
}

ConnectionPoint *PowerSource::getOutputPoint() const {
    return outputPoint;
}

void PowerSource::handleButtonClick(QGraphicsSceneMouseEvent *event) {
    ToggleState();
    qDebug() << "*** - Power Source Button was clicked";
}

void PowerSource::updateButtonAppearance(bool pressed) {
    if (pressed) {
        leftButton->moveBy(1, 1); // Move button slightly down and right
        leftButton->setBrush(Qt::darkGray); // Change color to indicate it's pressed
    } else {
        leftButton->moveBy(-1, -1); // Move button back to original position
        leftButton->setBrush(Qt::gray); // Change color back to original
    }
    // Update text position accordingly
    QRectF buttonRect = leftButton->rect();
    QRectF textRect = leftButtonText->boundingRect();
    leftButtonText->setPos(buttonRect.left() + (buttonRect.width() - textRect.width()) / 2,
                           buttonRect.top() + (buttonRect.height() - textRect.height()) / 2);
}


