//
// Created by John on 5/28/2024.
//
#include "LogicGates/AbstractTwoInputNode.hpp"

#ifndef LOGICGATES_EDITOR_QT_ANDGATE_HPP
#define LOGICGATES_EDITOR_QT_ANDGATE_HPP


class AndGate : public AbstractTwoInputNode {
public:

    AndGate();

    [[nodiscard]] State GetState() const override;
};


#endif //LOGICGATES_EDITOR_QT_ANDGATE_HPP
