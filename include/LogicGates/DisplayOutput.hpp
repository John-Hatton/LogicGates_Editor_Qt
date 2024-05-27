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

    State GetState() const override;

    // IObserver interface methods
    void Update(State state) override;

    ConnectionPoint* getInputPoint() const;
    ConnectionPoint* getOutputPoint() const;


protected:
    ConnectionPoint* inputPoint;

};


#endif //LOGICGATES_EDITOR_QT_DISPLAYOUTPUT_HPP
