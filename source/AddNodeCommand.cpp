//
// Created by John on 5/26/2024.
//

#include "AddNodeCommand.hpp"

#include <QUndoCommand>
#include <QGraphicsScene>
#include <Connection.hpp>

class AddConnectionCommand : public QUndoCommand {
public:
    AddConnectionCommand(QGraphicsScene *scene, Connection *connection, QUndoCommand *parent = nullptr)
            : QUndoCommand(parent), scene(scene), connection(connection) {}

    void undo() override {
        scene->removeItem(connection);
        delete connection;  // Optional: If you want to delete the connection on undo
    }

    void redo() override {
        scene->addItem(connection);
    }

private:
    QGraphicsScene *scene;
    Connection *connection;
};