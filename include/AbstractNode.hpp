//
// Created by John on 5/24/2024.
//
#pragma once //LOGICGATES_EDITOR_QT_ABSTRACTNODE_HPP

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <ConnectionPoint.hpp>
#include <NodeInterface.hpp>
#include <QBrush>
#include <QObject>
#include <QFont>
#include <QCursor>



class AbstractNode : public QObject, public QGraphicsRectItem, public ISubject, public IObserver{
Q_OBJECT

public:
    AbstractNode() : QObject(), QGraphicsRectItem(), dragging(false)
    {

        observers_ = {};

        setRect(0, 0, 100, 50);
        setFlag(QGraphicsItem::ItemIsMovable);
        setFlag(QGraphicsItem::ItemIsSelectable);

        QBrush brush(Qt::blue); // Set the fill color to blue
        setBrush(brush);        // Apply the brush to the rectangle

        // Add text background item
        textBackgroundItem = new QGraphicsRectItem(this);
        textBackgroundItem->setBrush(Qt::black);

        // Add node name item
        nodeNameItem = new QGraphicsTextItem(this);
        nodeNameItem->setDefaultTextColor(Qt::white);
        nodeNameItem->setFont(QFont("Arial", 12));

        // Add image item
        imageItem = new QGraphicsPixmapItem(this);
    }

    virtual void setNodeName(const QString &name)
    {
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
    virtual void setImage(const QPixmap &pixmap)
    {
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
    };

    virtual ConnectionPoint *getInputXPoint() const { return nullptr; };
    virtual ConnectionPoint *getInputYPoint() const { return nullptr; };
    virtual ConnectionPoint *getOutputXPoint() const { return nullptr; };
    virtual ConnectionPoint *getOutputYPoint() const { return nullptr; };



protected:
    bool dragging;
    QPointF dragStartPos;
    std::list<IObserver*> observers_;

    QGraphicsRectItem* textBackgroundItem;
    QGraphicsTextItem* nodeNameItem;
    QString nodeName;
    QGraphicsPixmapItem* imageItem;



signals:
    void positionChanged();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override = 0;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override = 0;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override = 0;

public:
    // ISubject interface methods
    void Attach(IObserver *observer) override{
        observers_.push_back(observer);
    }
    void Detach(IObserver *observer) override{
        observers_.remove(observer);
    }
    void Notify() override {
        for (auto observer : observers_) {
            observer->Update(GetState());
        }
    }

    std::list<IObserver*> GetObserversList()
    {
        return observers_;
    }

    virtual State GetState() const = 0;

    // IObserver interface methods
    virtual void Update(State state) override = 0;

    bool getHasInputNode() const {
        return hasInputNode;
    }

    void setHasInputNode(bool hasInputNode) {
        AbstractNode::hasInputNode = hasInputNode;
    }

    bool getHasOutputNode() const {
        return hasOutputNode;
    }

    void setHasOutputNode(bool hasOutputNode) {
        AbstractNode::hasOutputNode = hasOutputNode;
    }

    bool getHasTwoInputNodes() const {
        return hasTwoInputNodes;
    }

    void setHasTwoInputNodes(bool hasTwoInputNodes) {
        AbstractNode::hasTwoInputNodes = hasTwoInputNodes;
    }

    bool getHasTwoInputTwoOutput() const {
        return hasTwoInputTwoOutput;
    }

    void setHasTwoInputTwoOutput(bool hasTwoInputTwoOutput) {
        AbstractNode::hasTwoInputTwoOutput = hasTwoInputTwoOutput;
    }

    QString toString()
    {
        if (nodeName.length() > 0)
        {
            return nodeName;
        }
        else
        {
            return "AbstractNode (not initialized)";
        }
    }

private:

    bool hasInputNode = false;
    bool hasOutputNode = false;
    bool hasTwoInputNodes = false;
    bool hasTwoInputTwoOutput = false;

};
