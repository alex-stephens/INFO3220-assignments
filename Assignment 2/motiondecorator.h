#pragma once

#include <QSound>
#include <QSoundEffect>

#include "stickmandecorator.h"
#include "config.h"

class MotionDecorator : public StickmanDecorator
{
public:
    MotionDecorator(Stage2Stickman* stickman) : StickmanDecorator (stickman) {
        std::cout << "Constructing motion decorated stickman" << std::endl;

        effect.setSource(QUrl::fromLocalFile(":sound/jump.wav"));
        effect.setLoopCount(1); //QSoundEffect::Infinite);
        effect.setVolume(1.0f);
    }

    virtual bool jump() override;

private:
    QSoundEffect effect;
};
