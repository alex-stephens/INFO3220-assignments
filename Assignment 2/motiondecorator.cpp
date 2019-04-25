#include "motiondecorator.h"

void MotionDecorator::update() {
//  std::cout << "xVelocity : " << this->getXVelocity() << std::endl;
//    Config::config()->getStickman()->setXVelocity(0);
    StickmanDecorator::update(); // update by delegation

//  std::cout << "dynamics by delegation " << stickman->getXVelocity() << std::endl;
}
