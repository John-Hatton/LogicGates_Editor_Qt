//
// Created by John on 5/25/2024.
//
#include "ConnectionPoint.hpp"
#include <QBrush>
#include <QPen>

ConnectionPoint::ConnectionPoint(qreal x, qreal y, qreal radius, PointType type, QGraphicsItem *parent)
        : QObject(), QGraphicsEllipseItem(parent), pointType(type), scenePos(x, y) {
    setRect(x - radius, y - radius, radius * 2, radius * 2);
    setBrush(Qt::black);
    setPen(QPen(Qt::black));
    setAcceptHoverEvents(true);
}

void ConnectionPoint::setPosition(const QPointF &pos) {
    scenePos = pos;
    setPos(pos);
}

QString ConnectionPoint::toString() const {
    return QString("ConnectionPoint(type: %1, x: %2, y: %3)").arg(pointType == Input ? "Input" : "Output").arg(scenePos.x()).arg(scenePos.y());
}

void ConnectionPoint::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    setBrush(Qt::white);
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void ConnectionPoint::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    setBrush(Qt::black);
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

void ConnectionPoint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit connectionStarted(this);
        event->accept();
    } else {
        QGraphicsEllipseItem::mousePressEvent(event);
    }
}

void ConnectionPoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    emit connectionUpdated(event->scenePos());
    event->accept();
}

void ConnectionPoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit connectionEnded(this);
        event->accept();
    } else {
        QGraphicsEllipseItem::mouseReleaseEvent(event);
    }
}
