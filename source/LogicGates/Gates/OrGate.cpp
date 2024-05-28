//
// Created by John on 5/28/2024.
//

#include "LogicGates/Gates/OrGate.hpp"

OrGate::OrGate() {
    OrGate::setNodeName("Or Gate");
    QPixmap pixmap(":/resources/OrGate.png");
    OrGate::setImage(pixmap);
}

State OrGate::GetState() const {

    State output = DISABLED;
    if (inputX && inputY)
    {
        if (inputX->GetState() == DISABLED && inputY->GetState() == DISABLED)
        {
            output = DISABLED;
        }

        // If one or the other inputs are disabled

        if (inputX->GetState() == DISABLED || inputY->GetState() == DISABLED)
        {
            if (inputX->GetState() == ON && inputY->GetState() == DISABLED)
            {
                output = DISABLED;
            }
            else if (inputX->GetState() == DISABLED && inputY->GetState() == ON)
            {
                output = DISABLED;
            }
            else if (inputX->GetState() == OFF && inputY->GetState() == DISABLED)
            {
                output = DISABLED;
            }
            else if (inputX->GetState() == DISABLED && inputY->GetState() == OFF)
            {
                output = DISABLED;
            }
        }
        else {
            // Neither input contained DISABLED...

            if (inputX->GetState() == ON || inputY->GetState() == ON) {
                output = ON;
            } else if (inputX->GetState() == OFF && inputY->GetState() == OFF) {
                output = OFF;
            }
        }
    } else {
        std::cout<<"Both Inputs of OrGate weren't populated yet..." << std::endl;
        output = DISABLED;
    }
    return output;
}
