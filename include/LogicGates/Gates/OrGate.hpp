//
// Created by John on 5/28/2024.
//
#include "LogicGates/AbstractTwoInputNode.hpp"

#ifndef LOGICGATES_EDITOR_QT_ORGATE_HPP
#define LOGICGATES_EDITOR_QT_ORGATE_HPP


class OrGate : public AbstractTwoInputNode {
public:

    OrGate();

    [[nodiscard]] State GetState() const override;
};


#endif //LOGICGATES_EDITOR_QT_ORGATE_HPP
