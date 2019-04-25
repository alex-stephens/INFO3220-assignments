#pragma once

#include "stickmandecorator.h"

class MotionDecorator : public StickmanDecorator
{
public:
    MotionDecorator(Stage2Stickman* stickman) : StickmanDecorator (stickman) {}
    void update() override {
        StickmanDecorator::update(); // update by delegation
        std::cout << "dynamics by delegation" << std::endl;
    }
};
