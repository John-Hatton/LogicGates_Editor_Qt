//
// Created by John on 5/26/2024.
//
#include <QUndoCommand>
#include <QGraphicsScene>
#include "Node.hpp"


#ifndef LOGICGATES_EDITOR_QT_ADDNODECOMMAND_HPP
#define LOGICGATES_EDITOR_QT_ADDNODECOMMAND_HPP

class AddNodeCommand : public QUndoCommand {
public:
    AddNodeCommand(QGraphicsScene *scene, Node *node, QUndoCommand *parent = nullptr)
            : QUndoCommand(parent), scene(scene), node(node) {}

    void undo() override {
        scene->removeItem(node);
        delete node;  // Optional: If you want to delete the node on undo
    }

    void redo() override {
        scene->addItem(node);
    }

private:
    QGraphicsScene *scene;
    Node *node;
};


#endif //LOGICGATES_EDITOR_QT_ADDNODECOMMAND_HPP
