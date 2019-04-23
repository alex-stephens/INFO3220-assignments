#pragma once

#include "gamefactory.h"
#include "stage2game.h"

class Stage2GameFactory : public GameFactory
{
public:
    Stage2GameFactory() = default;
    ~Stage2GameFactory() = default;

    Stage2Game* createGame() override {
        return new Stage2Game();
    }
};
