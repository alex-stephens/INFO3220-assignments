#ifndef FLYINGSTICKMAN_H
#define FLYINGSTICKMAN_H

#include "jumpingstickman.h"
#include "collision.h"
#include <set>

class FlyingStickman : public JumpingStickman
{
public:
    FlyingStickman(int floor, int jumpImpulse = 15, int maxJumpCount = 2, int gravity = -1);
    virtual ~FlyingStickman();

    virtual void handleInput(QKeyEvent &event);
    virtual void update(std::vector<std::unique_ptr<Entity>> &obstacles) override;

    virtual void setSprite(std::string path) override;

    virtual void notify(int val) override;

protected:
    std::set<int> keysPressed;

};

#endif // FLYINGSTICKMAN_H
