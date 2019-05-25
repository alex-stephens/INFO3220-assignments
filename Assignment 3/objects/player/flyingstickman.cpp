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
    for (auto &other : obstacles) {
        Collision::CollisonResult col = Collision::moveCast(*this, *other, getVelocity(), getJumpVelocity());

        if (col.overlapped) {
            int bx = other->getCoordinate().getXCoordinate();
            int by = other->getCoordinate().getYCoordinate();
            if (col.down && getJumpVelocity() < 0) {
                // Hitting obstacle from above
                setJumpVelocity(0);
                setGrounded(true);
                setJumpCount(0);
                newY = by + other->height() + 1;
            } else if (col.up) {
                // Hitting obstacle from below
                setJumpVelocity(0);
                newY = by - height() - 1;
            } else if (col.right) {
                // Hidding obstacle from the left
                newX = bx - width() - 1;
                colliding = true;
                std::cout << "hit from left" << std::endl;
            } else if (col.left) {
                // Hidding obstacle from the right
                newX = bx + 1;
                colliding = true;
                std::cout << "hit from right" << std::endl;
            }
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
