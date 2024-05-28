//
// Created by John on 5/28/2024.
//

#include "LogicGates/Gates/AndGate.hpp"

AndGate::AndGate() {
    AndGate::setNodeName("And Gate");
    QPixmap pixmap(":/resources/AndGate.png");
    AndGate::setImage(pixmap);
}

State AndGate::GetState() const {

    State output = DISABLED;
    if (inputX && inputY)
    {
        if (inputX->GetState() == DISABLED || inputY->GetState() == DISABLED)
        {
            // Case 1 D,D
            if (inputX->GetState() == DISABLED && inputY->GetState() == DISABLED)
            {
                output = DISABLED;
            }
                // Case 2 D,F
            else if (inputX->GetState() == DISABLED && inputY->GetState() == OFF)
            {
                output = DISABLED;
            }
                // Case 3 F,D
            else if (inputX->GetState() == OFF && inputY->GetState() == DISABLED)
            {
                output = DISABLED;
            }
                // Case 4 D,T
            else if (inputX->GetState() == DISABLED && inputY->GetState() == ON)
            {
                output = DISABLED;
            }
                // Case 5 T,D
            else if (inputX->GetState() == ON && inputY->GetState() == DISABLED)
            {
                output = DISABLED;
            }
        }
            // Neither input was Disabled:
        else
        {
            // Case 6 F,F
            if (inputX->GetState() == OFF && inputY->GetState() == OFF)
            {
                output = OFF;
            }
                // Case 7 F,T
            else if (inputX->GetState() == OFF && inputY->GetState() == ON)
            {
                output = OFF;
            }
                // Case 8 T,F
            else if (inputX->GetState() == ON && inputY->GetState() == OFF)
            {
                output = OFF;
            }
                // Case 9 T,T
            else if (inputX->GetState() == ON && inputY->GetState() == ON)
            {
                output = ON;
            }
        }
    }
    else {
        std::cout<< "Both Inputs of AndGate weren't populated yet..." << std::endl;
        output = DISABLED;
    }
    return output;
}