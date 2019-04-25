#pragma once

#include "stage2stickman.h"

class StickmanDecorator : public Stage2Stickman
{
    Stage2Stickman* stickman;

public:
    StickmanDecorator(Stage2Stickman* stickman) : stickman(stickman) { }
    void update() override {
        stickman->update(); // update by delegation
    }
};

