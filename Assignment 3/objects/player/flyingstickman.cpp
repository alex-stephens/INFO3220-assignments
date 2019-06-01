#include "flyingstickman.h"
#include <iostream>

FlyingStickman::FlyingStickman(int floor, int jumpImpulse, int maxJumpCount, int gravity) :
    JumpingStickman(floor, jumpImpulse, maxJumpCount, gravity) {

}

FlyingStickman::~FlyingStickman() {

}


void FlyingStickman::handleInput(QKeyEvent &event) {

    if (event.type() == QEvent::KeyPress && !event.isAutoRepeat()) {
        keysPressed.insert(event.key());
    }
    else if (event.type() == QEvent::KeyRelease && !event.isAutoRepeat()) {
        for (auto it = keysPressed.begin(); it != keysPressed.end(); ) {
            if (*it == event.key()) {
                it = keysPressed.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    // jump -- single press event
    if (event.type() == QEvent::KeyPress && (event.key() == Qt::Key_Space || event.key() == Qt::Key_Up) && !event.isAutoRepeat() && canJump()) {
        jump();
    }
}

// Resize stickman based on size attribute
void FlyingStickman::setSprite(std::string path) {
    QPixmap newSprite(QString::fromStdString(path));
    if (size.compare("tiny") == 0) {
        sprite = newSprite.scaledToHeight(24);
        setJumpImpulse(15);

    } else if(size.compare("normal") == 0) {
        sprite = newSprite.scaledToHeight(48);
        setJumpImpulse(15);

    } else if(size.compare("large") == 0) {
        sprite = newSprite.scaledToHeight(72);
        setJumpImpulse(20);

    } else {
        sprite = newSprite.scaledToHeight(96);
        setJumpImpulse(20);
    }
}



void FlyingStickman::update(std::vector<std::unique_ptr<Entity>> &obstacles) {
    Coordinate &ac = getCoordinate();
    int newX = ac.getXCoordinate() + getVelocity();
    int newY = ac.getYCoordinate() + getJumpVelocity();
    bool bump;
    colliding = false;

    // lateral movement
    if (keysPressed.find(Qt::Key_Left) != keysPressed.end() ) {
        setVelocity(-10);
    }

    if (keysPressed.find(Qt::Key_Right) != keysPressed.end() ) {
        setVelocity(10);
    }

    // Check for collisions
    for (auto it = obstacles.begin(); it != obstacles.end(); ) {
        auto &other = *it;
        Collision::CollisonResult col = Collision::moveCast(*this, *other, getVelocity(), getJumpVelocity());
        bump = false;

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
            } else if (col.left) {
                // Hitting obstacle from the right
                newX = bx + 1;
                colliding = true;
                bump = true;
            }
        }

        // set size from powerup
        if (bump && (other->getName() == "powerup")) {
            setSize( other->getSizeString());
            it = obstacles.erase(it);
            colliding = false;
        }

        // update score from coin
        if (bump && (other->getName() == "coin")) {
            it = obstacles.erase(it);
            colliding = false;
            updateObservers(SCORE_POWERUP);
        }

        // giant stickman destroys obstacles
        else if (bump && getSize() == "giant") {
            it = obstacles.erase(it);
            updateObservers(SCORE_OBSTACLE);
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

    ac.setYCoordinate(newY);
    setJumpVelocity(getJumpVelocity() + getGravity());

    // update observer score from motion
    updateObservers(getVelocity() * SCORE_MOTION);

}

// Draw and update stickman position
void FlyingStickman::render(Renderer &renderer, unsigned int time) {
    renderer.draw(coordinate.getQtRenderingXCoordinate(), coordinate.getQtRenderingYCoordinate() - sprite.height(), sprite);
    std::string spritePath = ":sprites/sprite";

    observer.render(renderer);

    // use mirrored sprite if moving to the left
    if (getVelocity() < 0) {
        spritePath = ":sprites/sprite_rev";
    }

    // only update the sprite if the stickman is moving
    if (getVelocity() != 0) {
        this->setSprite(spritePath.append(std::to_string((time/5)%2)).append(".png"));
    }
}

