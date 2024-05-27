//
// Created by John on 5/25/2024.
//

#include <Connection.hpp>
#include <QGraphicsScene>

Connection::Connection(ConnectionPoint *start, ConnectionPoint *end, QGraphicsScene *scene)
        : QObject(), QGraphicsLineItem(), startPoint(start), endPoint(end) {

    setZValue(-1); // Ensure connections are drawn behind other items
    pen.setWidth(2); // Adjust the thickness of the connection
    setPen(pen);
    scene->addItem(this);
    update();
}

void Connection::update() {
    setLine(QLineF(startPoint->getScenePosition(), endPoint->getScenePosition()));
}

void Connection::setColor(Qt::GlobalColor color) {
    pen.setColor(color);
    setPen(pen);
}

ConnectionPoint *Connection::getStartPoint() const {
    return startPoint;
}

void Connection::setStartPoint(ConnectionPoint *startPoint) {
    Connection::startPoint = startPoint;
}

ConnectionPoint *Connection::getEndPoint() const {
    return endPoint;
}

void Connection::setEndPoint(ConnectionPoint *endPoint) {
    Connection::endPoint = endPoint;
}
