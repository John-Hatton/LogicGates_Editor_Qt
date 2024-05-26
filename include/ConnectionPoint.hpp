//
// Created by John on 5/25/2024.
//

#pragma once

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class ConnectionPoint : public QObject, public QGraphicsEllipseItem {
Q_OBJECT

public:
    enum PointType { Input, Output };

    ConnectionPoint(qreal x, qreal y, qreal radius, PointType type, QGraphicsItem *parent = nullptr);
    void setPosition(const QPointF &pos);
    QPointF getScenePosition() const { return mapToScene(rect().center()); }
    PointType getPointType() const { return pointType; }
    QString toString() const;

signals:
    void connectionStarted(ConnectionPoint *point);
    void connectionUpdated(const QPointF &pos);
    void connectionEnded(ConnectionPoint *point);
    void connectionCanceled();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    PointType pointType;
    QPointF scenePos;
};

