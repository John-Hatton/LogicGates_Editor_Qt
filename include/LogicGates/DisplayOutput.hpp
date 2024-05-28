//
// Created by John on 5/27/2024.
//
#include <AbstractNode.hpp>

#ifndef LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP
#define LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP


class DisplayOutput : public AbstractNode {


public:
    DisplayOutput();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void setInput(AbstractNode* input);

    State GetState() const override;

    // IObserver interface methods
    void Update(State state) override;

    ConnectionPoint *getInputXPoint() const override;


protected:

    std::list<IObserver*> connectedNodes_;
    AbstractNode* input_;
    State state_ = DISABLED;

    ConnectionPoint* inputPoint;

    QGraphicsRectItem* stateDisplay;



};


#endif //LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP
