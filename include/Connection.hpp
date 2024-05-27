//
// Created by John on 5/25/2024.
//
#include <QGraphicsLineItem>
#include <ConnectionPoint.hpp>
#include <QPen>

#pragma once //LOGICGATES_EDITOR_QT_CONNECTION_HPP

class Connection : public QObject, public QGraphicsLineItem {
Q_OBJECT


public:
    Connection(ConnectionPoint *start, ConnectionPoint *end, QGraphicsScene *scene);
    void setColor(Qt::GlobalColor color);
    void update();

    ConnectionPoint *getStartPoint() const;

    void setStartPoint(ConnectionPoint *startPoint);

    ConnectionPoint *getEndPoint() const;

    void setEndPoint(ConnectionPoint *endPoint);

private:
    ConnectionPoint* startPoint;
    ConnectionPoint* endPoint;
    QPen pen;


};
