#include "motiondecorator.h"

bool MotionDecorator::jump() {

    bool jumped = StickmanDecorator::jump();
    if (jumped) {
        effect.play();
    }
    return jumped;
}
