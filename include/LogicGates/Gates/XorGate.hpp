//
// Created by John on 5/27/2024.
//
#include "LogicGates/AbstractTwoInputNode.hpp"

#ifndef LOGICGATES_EDITOR_QT_XORGATE_HPP
#define LOGICGATES_EDITOR_QT_XORGATE_HPP


class XorGate : public AbstractTwoInputNode
{
public:

    XorGate();

    [[nodiscard]] State GetState() const override;

};


#endif //LOGICGATES_EDITOR_QT_XORGATE_HPP
