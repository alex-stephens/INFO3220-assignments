#include "flyingstickman.h"
#include <iostream>

FlyingStickman::FlyingStickman(int floor, int jumpImpulse, int maxJumpCount, int gravity) :
    JumpingStickman(floor, jumpImpulse, maxJumpCount, gravity)  {

}

FlyingStickman::~FlyingStickman() {

}

void FlyingStickman::handleInput(QKeyEvent &event) {
    if ((event.key() == Qt::Key_Space || event.key() == Qt::Key_Up) && !event.isAutoRepeat() && canJump()) {
        jump();
        std::cout << "jumping" << std::endl;
    }

    else if (event.key() == Qt::Key_Left ) {
        setVelocity(-20);
    }

    else if (event.key() == Qt::Key_Right) {
        setVelocity(20);
    }

    else if (event.key() == Qt::Key_X) {
        setSize("giant");
    }
}


void FlyingStickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {
    Coordinate &ac = getCoordinate();
    int newX = ac.getXCoordinate() + getVelocity();
    int newY = ac.getYCoordinate() + getJumpVelocity();
    colliding = false;

    // Check for collisions
    for (auto it = obstacles.begin(); it != obstacles.end(); ) {
        auto &other = *it;
        Collision::CollisonResult col = Collision::moveCast(*this, *other, getVelocity(), getJumpVelocity());
        bool bump = false;

        if (col.overlapped) {
            int bx = other->getCoordinate().getXCoordinate();
            int by = other->getCoordinate().getYCoordinate();
            if (col.down && getJumpVelocity() < 0) {
                // Hitting obstacle from above
                setJumpVelocity(0);
                setGrounded(true);
                setJumpCount(0);
                newY = by + other->height() + 1;
                bump = true;
            } else if (col.up) {
                // Hitting obstacle from below
                setJumpVelocity(0);
                newY = by - height() - 1;
                bump = true;
            } else if (col.right) {
                // Hitting obstacle from the left
                newX = bx - width() - 1;
                colliding = true;
                bump = true;
                std::cout << "hit from left" << std::endl;
            } else if (col.left) {
                // Hitting obstacle from the right
                newX = bx + 1;
                colliding = true;
                bump = true;
                std::cout << "hit from right" << std::endl;
            }
        }

        if (bump && other->getName() == "powerup") {
            setSize( other->getSizeString());
            it = obstacles.erase(it);
            std::cout << "POWER UP MOTHERFUCKER" << std::endl;

        }
        else {
            ++it;
        }
    }

    // Check if we're below the floor
    if (newY <= getFloor()) {
        newY = getFloor();
        setGrounded(true);
        setJumpVelocity(0);
        setJumpCount(0);
    }

    if (colliding) {
        setVelocity(0);
    }

    ac.setYCoordinate(newY);
//    ac.setXCoordinate(newX);
    setJumpVelocity(getJumpVelocity() + getGravity());
}
