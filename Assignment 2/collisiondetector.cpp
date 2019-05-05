#include "collisiondetector.h"

CollisionDetector::CollisionDetector(std::vector<Obstacle>& obstacles)
    : obstacles(obstacles) {

    effect.setSource(QUrl::fromLocalFile(":sound/bump.wav"));
    effect.setLoopCount(1); //QSoundEffect::Infinite);
    effect.setVolume(0.2f);
}

void CollisionDetector::checkCollisions() {
    Stage2Stickman * stickman = Config::config()->getStickman();
    int x1, x2, y1, y2;
    x1 = stickman->getXPosition() - stickman->getWidth()/2; x2 = x1 + stickman->getWidth();
    y1 = stickman->getYPosition() + stickman->getHeight(); y2 = y1 - stickman->getHeight();

    for (Obstacle o : obstacles) {
        int x3, x4, y3, y4;

        int yvel = Config::config()->getStickman()->getYVelocity();
        x3 = o.getCoordinate().getXCoordinate(); x4 = x3 + o.getWidth();
        y3 = o.getCoordinate().getYCoordinate(); y4 = y3 - o.getHeight();

        // upward collision
        if (yvel > 0 && (x1 < x4 != x2 < x3) && (y1+yvel > y4 && y2 <= y4)) {
            upward_collision = true;
            collisionY = y4 - Config::config()->getStickman()->getHeight();
            std::cout << "upward collision" << std::endl;
        }
        // downward collision
        if (yvel < 0 && (x1 < x4 != x2 < x3) && (y2+yvel < y3 && y1 >= y4)) {
            downward_collision = true;
            collisionY = y3;
            std::cout << "downward collision" << std::endl;
        }

        // horizontal collision
        int xvel = Config::config()->getStickman()->getXVelocity();
        x3 = o.getCoordinate().getXCoordinate(); x4 = x3 + o.getWidth();
        y3 = o.getCoordinate().getYCoordinate(); y4 = y3 - o.getHeight();

        if ((x1 < x4 != x2+xvel < x3) && (y1 < y4 != y2 < y3)) {
            horizontal_collision = true;
            upward_collision = false;
            downward_collision = false;
            collisionX = x3 - Config::config()->getStickman()->getWidth();
            std::cout << "horizontal collision" << std::endl;
            break;
        }
    }
}

void CollisionDetector::applyCollisions() {

    if (horizontal_collision) {
        Config::config()->getStickman()->setXVelocity(0);
    }
    else {
        Config::config()->getStickman()->setXVelocityToDefault();
    }

    if (upward_collision && Config::config()->getStickman()->getYVelocity() > 0) {
        Config::config()->getStickman()->setYVelocity(0);
        Config::config()->getStickman()->setYPosition(collisionY);
    }
    else if (downward_collision && Config::config()->getStickman()->getYVelocity() < 0) {
        Config::config()->getStickman()->setYVelocity(0);
        Config::config()->getStickman()->setYPosition(collisionY);
        Config::config()->getStickman()->setJumpCtr(0);
    }

    if (horizontal_collision) {
        std::cout << "horizontal collision" <<std::endl;
    }
    else {
        std::cout << "NO horizontal collision" <<std::endl;

    }

    if (horizontal_collision || upward_collision || downward_collision) {
        if (prev_collision >= 3) {
            effect.play();
        }
        prev_collision = 0;
    }
    else {
        ++prev_collision;
    }


    // reset collision variables
    horizontal_collision = false;
    upward_collision = false;
    downward_collision = false;

}
