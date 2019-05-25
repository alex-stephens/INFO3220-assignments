#ifndef JUMPINGSTICKMAN_H
#define JUMPINGSTICKMAN_H

#include <memory>
#include "entity.h"
#include "stickman.h"

class JumpingStickman : public Stickman {
public:
    /**
     * @brief JumpingStickman An extension of the Stickman class which adds jumping and collision detection
     * @param floor The y position which is considered the floor (i.e. will stop falling at)
     * @param jumpImpulse The vertical velocity applied when jumping
     * @param maxJumpCount The maximum amount of jumps that can be peformed mid-air (including the initial jump)
     * @param gravity The falling rate
     */
    JumpingStickman(int floor, int jumpImpulse = 15, int maxJumpCount = 2, int gravity = -1);
    virtual ~JumpingStickman();

    void jump();
    bool canJump();

    virtual void handleInput(QKeyEvent &event);
    virtual void update(std::vector<std::unique_ptr<Entity>> &obstacles);

//    virtual void notify(int val) override;


    // getters and setters for stage 3
    int getJumpVelocity() { return jumpVelocity; }
    int getGravity() { return gravity; }
    int getFloor() { return floor; }

    void setJumpVelocity(int val) { jumpVelocity = val; }
    void setJumpImpulse(int val) { jumpImpulse = val; }
    void setJumpCount(int val) { jumpCount = val; }
    void setGrounded(bool val) { grounded = val; }


private:
    int jumpImpulse;
    int jumpVelocity;
    int floor;
    int gravity;
    bool grounded;
    int jumpCount;
    int maxJumpCount;
};

#endif // JUMPINGSTICKMAN_H
