//
// Created by John on 5/24/2024.
//
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#ifndef COLORSTEALQT_NODE_HPP
#define COLORSTEALQT_NODE_HPP


class Node : public QGraphicsRectItem {
public:
    Node();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool dragging;
    QPointF dragStartPos;
};


#endif //COLORSTEALQT_NODE_HPP
