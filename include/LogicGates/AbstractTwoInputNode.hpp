//
// Created by John on 5/27/2024.
//
#include "AbstractNode.hpp"
#include <iostream>

#ifndef LOGICGATES_EDITOR_QT_ABSTRACTTWOINPUTNODE_HPP
#define LOGICGATES_EDITOR_QT_ABSTRACTTWOINPUTNODE_HPP


class AbstractTwoInputNode : public AbstractNode {
protected:
    AbstractNode* inputX;
    AbstractNode* inputY;

    ConnectionPoint* inputPointX;
    ConnectionPoint* inputPointY;
    ConnectionPoint* outputPoint;
    State outputState_;
    std::list<IObserver*> connectedNodes_;

public:

    AbstractTwoInputNode();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void setInputX(AbstractNode* input);
    virtual void setInputY(AbstractNode* input);
    virtual void removeInputX();
    virtual void removeInputY();

    virtual void Update(State state) override;

    ConnectionPoint *getInputXPoint() const override;
    ConnectionPoint *getInputYPoint() const override;
    ConnectionPoint *getOutputXPoint() const override;
};


#endif //LOGICGATES_EDITOR_QT_ABSTRACTTWOINPUTNODE_HPP
