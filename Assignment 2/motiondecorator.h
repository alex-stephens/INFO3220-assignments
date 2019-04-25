#pragma once

#include "stickmandecorator.h"

class MotionDecorator : public StickmanDecorator
{
public:
    MotionDecorator(Stage2Stickman* stickman) : StickmanDecorator (stickman) {
        std::cout << "Constructing motion decorated stickman" << std::endl;
        std::cout << "xVelocity : " << this->getXVelocity() << std::endl;
    }
    void update() override {
//        stickman->
        StickmanDecorator::update(); // update by delegation
//        std::cout << "dynamics by delegation " << stickman->getXVelocity() << std::endl;
    }
};
