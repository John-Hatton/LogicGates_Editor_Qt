//
// Created by John on 5/28/2024.
//
#include "LogicGates/AbstractTwoInputNode.hpp"

#ifndef LOGICGATES_EDITOR_QT_BUFFERGATE_HPP
#define LOGICGATES_EDITOR_QT_BUFFERGATE_HPP


class BufferGate : public AbstractTwoInputNode {
public:

    BufferGate();

    [[nodiscard]] State GetState() const override;
};


#endif //LOGICGATES_EDITOR_QT_BUFFERGATE_HPP
