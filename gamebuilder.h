#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include "config.h"
#include "background.h"
#include "coordinate.h"
#include "sprite.h"
#include "game.h"
#include "builder.h"

#include <QSound>

class GameBuilder : public Builder
{
public:
    GameBuilder(Config config);

    void setConfig(Config c);

    void setSprite(QString filename, QString extension, int numImages);

    void addSoundtrack();

    virtual ~GameBuilder();

    Game * buildGame();


private:
    Config config;
    Background background;
    Sprite sprite;
};

#endif // GAMEBUILDER_H
