#pragma once

#include <QSound>
#include <QSoundEffect>

#include "stickmandecorator.h"
#include "config.h"

class MotionDecorator : public StickmanDecorator
{
public:
    MotionDecorator(Stage2Stickman* stickman);

    virtual bool jump() override;

private:
    QSoundEffect effect;
};
