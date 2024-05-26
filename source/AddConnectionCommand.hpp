//
// Created by John on 5/26/2024.
//
#include <QUndoCommand>
#include <QGraphicsScene>
#include <Connection.hpp>

#ifndef LOGICGATES_EDITOR_QT_ADDCONNECTIONCOMMAND_HPP
#define LOGICGATES_EDITOR_QT_ADDCONNECTIONCOMMAND_HPP


class AddConnectionCommand : public QUndoCommand {
public:
    AddConnectionCommand(QGraphicsScene *scene, Connection *connection, QUndoCommand *parent = nullptr)
            : QUndoCommand(parent), scene(scene), connection(connection) {}

    void undo() override {
        scene->removeItem(connection);
        connection->setVisible(false);
    }

    void redo() override {
        scene->addItem(connection);
        connection->setVisible(true);
    }

private:
    QGraphicsScene *scene;
    Connection *connection;
};


#endif //LOGICGATES_EDITOR_QT_ADDCONNECTIONCOMMAND_HPP
