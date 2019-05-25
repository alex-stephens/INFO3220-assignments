#ifndef FLYINGSTICKMAN_H
#define FLYINGSTICKMAN_H

#include "jumpingstickman.h"
#include "collision.h"

class FlyingStickman : public JumpingStickman
{
public:
    FlyingStickman(int floor, int jumpImpulse = 15, int maxJumpCount = 2, int gravity = -1);
    ~FlyingStickman();

    virtual void handleInput(QKeyEvent &event);
    virtual void update(std::vector<std::unique_ptr<Entity>> &obstacles) override;

    virtual void setSprite(std::string path) override;

};

#endif // FLYINGSTICKMAN_H
