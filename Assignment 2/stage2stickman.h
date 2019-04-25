#pragma once

#include "stickman.h"

class Stage2Stickman : public Stickman
{

public:
    using Stickman::Stickman;
    ~Stage2Stickman() = default;

    // Getters
    int getYPosition() { return yposition; }
    double getYVelocity() { return yvelocity; }

    // Setters
    void changeYPosition(int new_position) { yposition = new_position; }
    void changeYVelocity(int new_velocity) { yvelocity = new_velocity; }
    void changePosition(int x, int y) { changeXPosition(x); changeYPosition(y); }

    void jump();
    virtual void update(void) override;


private:
    int yposition;
    double yvelocity;
    int jumpctr = 0; // used to implement double jump
};
