#pragma once

#include "stickmandecorator.h"
#include "config.h"

class MotionDecorator : public StickmanDecorator
{
public:
    MotionDecorator(Stage2Stickman* stickman) : StickmanDecorator (stickman) {
        std::cout << "Constructing motion decorated stickman" << std::endl;
    }
    void update() override;
};
