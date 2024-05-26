//
// Created by John on 5/24/2024.
//
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <ConnectionPoint.hpp>
#include <Editor.hpp>


#ifndef LOGICGATES_EDITOR_QT_NODE_HPP
#define LOGICGATES_EDITOR_QT_NODE_HPP

class Node : public QObject, public QGraphicsRectItem {
Q_OBJECT

public:
    Node(Editor* editor);

    void setNodeName(const QString &name);
    void setImage(const QPixmap &pixmap);

signals:
    void positionChanged();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool dragging;
    QPointF dragStartPos;
    Editor* editor;
    ConnectionPoint* inputPoint;
    ConnectionPoint* outputPoint;
    QGraphicsTextItem* nodeNameItem;
    QGraphicsPixmapItem* imageItem;
    QGraphicsRectItem* textBackgroundItem;
};

#endif //LOGICGATES_EDITOR_QT_NODE_HPP
