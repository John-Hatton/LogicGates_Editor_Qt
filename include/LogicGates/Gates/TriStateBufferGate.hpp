//
// Created by John on 5/28/2024.
//
#include "LogicGates/AbstractTwoInputNode.hpp"

#ifndef LOGICGATES_EDITOR_QT_TRISTATEBUFFERGATE_HPP
#define LOGICGATES_EDITOR_QT_TRISTATEBUFFERGATE_HPP


class TriStateBufferGate : public AbstractTwoInputNode {
public:

    TriStateBufferGate();

    [[nodiscard]] State GetState() const override;
};


#endif //LOGICGATES_EDITOR_QT_TRISTATEBUFFERGATE_HPP
