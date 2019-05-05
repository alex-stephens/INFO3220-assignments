#include "motiondecorator.h"

MotionDecorator::MotionDecorator(Stage2Stickman * stickman)
    : StickmanDecorator (stickman) {

    effect.setSource(QUrl::fromLocalFile(":sound/jump.wav"));
    effect.setLoopCount(1); //QSoundEffect::Infinite);
    effect.setVolume(1.0f);
}

bool MotionDecorator::jump() {

    bool jumped = StickmanDecorator::jump();
    if (jumped) {
        effect.play();
    }
    return jumped;
}
