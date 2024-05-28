//
// Created by John on 5/26/2024.
//

#include <QPushButton>
#include "AbstractNode.hpp"

#ifndef LOGICGATES_EDITOR_QT_POWERSOURCE_HPP
#define LOGICGATES_EDITOR_QT_POWERSOURCE_HPP


class PowerSource : public AbstractNode {

private:
    State state_;

public:
    PowerSource();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void ChangeState(State state);
    void ToggleState();
    State GetState() const override;

    // IObserver interface methods
    void Update(State state) override;

    ConnectionPoint *getOutputXPoint() const override;


protected:
    ConnectionPoint* outputPoint;
    QGraphicsRectItem* toggleStateButton;
    QGraphicsTextItem* toggleStateButtonText;
    QGraphicsRectItem* stateDisplay;
    bool buttonPressed;

    void handleButtonClick(QGraphicsSceneMouseEvent *event);

    void updateButtonAppearance(bool pressed);
};


#endif //LOGICGATES_EDITOR_QT_POWERSOURCE_HPP
