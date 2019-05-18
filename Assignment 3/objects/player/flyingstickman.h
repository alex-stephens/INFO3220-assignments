#ifndef FLYINGSTICKMAN_H
#define FLYINGSTICKMAN_H

#include "jumpingstickman.h"

class FlyingStickman : public JumpingStickman
{
public:
    FlyingStickman(int floor, int jumpImpulse = 15, int maxJumpCount = 2, int gravity = -1);
    ~FlyingStickman();
};

#endif // FLYINGSTICKMAN_H
