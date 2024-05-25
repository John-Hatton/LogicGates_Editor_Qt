//
// Created by John on 5/25/2024.
//

#include <Connection.hpp>
#include <QGraphicsScene>

Connection::Connection(ConnectionPoint *start, ConnectionPoint *end, QGraphicsScene *scene)
        : QObject(), QGraphicsLineItem(), startPoint(start), endPoint(end) {
    setZValue(-1); // Ensure connections are drawn behind other items
    QPen pen;
    pen.setWidth(2); // Adjust the thickness of the connection
    setPen(pen);
    scene->addItem(this);
    update();
}

void Connection::update() {
    setLine(QLineF(startPoint->getScenePosition(), endPoint->getScenePosition()));
}