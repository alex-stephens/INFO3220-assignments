#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "config.h"
#include "background.h"
#include "coordinate.h"
#include "sprite.h"
#include "game.h"


class GameBuilder
{
public:
    GameBuilder(Config config);


//    void setBackground(Config config);
    void setConfig(Config c);
    void setSprite(QString filename, QString extension, int numImages);

    ~GameBuilder() {

    }

    Game * buildGame();


private:
    Config config;
    Background background;
    Sprite sprite;
};

#endif // GAMEBUILDER_H
