//
// Created by John on 5/28/2024.
//

#include "LogicGates/Gates/TriStateBufferGate.hpp"

TriStateBufferGate::TriStateBufferGate() {

}

State TriStateBufferGate::GetState() const {
    return DISABLED;
}
