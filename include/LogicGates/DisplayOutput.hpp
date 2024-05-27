//
// Created by John on 5/27/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP
#define LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP


class DisplayOutput : public AbstractNode {


public:
    DisplayOutput();

    void setNodeName(const QString &name) override;
    void setImage(const QPixmap &pixmap) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void setInput(AbstractNode* input);

    State GetState() const override;

    // IObserver interface methods
    void Update(State state) override;

    ConnectionPoint* getInputPoint() const;
    ConnectionPoint* getOutputPoint() const;


protected:

    std::list<IObserver*> connectedNodes_;
    AbstractNode* input_;
    State state_ = DISABLED;

    ConnectionPoint* inputPoint;

    QGraphicsRectItem* rightBox;



};


#endif //LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP
