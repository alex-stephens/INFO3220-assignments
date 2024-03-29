#pragma once

#include "stickman.h"

class Stage2Stickman : public Stickman
{

public:
    using Stickman::Stickman;
    ~Stage2Stickman() = default;

    // Getters
    virtual int getYPosition() { return yposition; }
    virtual double getYVelocity() { return yvelocity; }
    virtual int getDefaultVelocity() { return default_velocity; }

    // Setters
    virtual void setYPosition(int new_position) { yposition = new_position; }
    virtual void setYVelocity(int new_velocity) { yvelocity = new_velocity; }
    virtual void setXVelocityToDefault() { this->setXVelocity(default_velocity); }
    virtual void setPosition(int x, int y) { setXPosition(x); setYPosition(y); }
    virtual void setJumpCtr(int j) { jumpctr = j; }
    virtual void setDefaultVelocity (int vel) { default_velocity = vel; }

    virtual bool jump();
    virtual void update();

    virtual void setJumpVelocity(int vel) { jump_vel = vel; }
    virtual void setGravity(int g) { gravity = g; }


private:
    double yvelocity = 0;
    int yposition = 0 ;
    int default_velocity = this->getXVelocity();
    int jumpctr = 0; // used to implement double/multi jump

    int jump_vel = 30;
    int gravity = 2;
};
