//
// Created by John on 5/25/2024.
//
#include <QGraphicsLineItem>
#include <ConnectionPoint.hpp>

#pragma once //LOGICGATES_EDITOR_QT_CONNECTION_HPP

class Connection : public QObject, public QGraphicsLineItem {
Q_OBJECT

public:
    Connection(ConnectionPoint *start, ConnectionPoint *end, QGraphicsScene *scene);

    void update();

private:
    ConnectionPoint *startPoint;
    ConnectionPoint *endPoint;
};
