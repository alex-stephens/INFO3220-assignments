#include "motiondecorator.h"

void MotionDecorator::update() {
//  std::cout << "xVelocity : " << this->getXVelocity() << std::endl;
    if (Config::config()->getStickman()->getXPosition() >= 1000) {
        Config::config()->getStickman()->setXVelocity(0);
    }
//    Config::config()->getStickman()->setXVelocity(0);
    StickmanDecorator::update(); // update by delegation
}
