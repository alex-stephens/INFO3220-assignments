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
    /**
     * @brief GameBuilder constructor from configuration
     * @param config object
     */
    GameBuilder(Config config);

    /**
     * @brief setConfig
     * @param c
     */
    void setConfig(Config c);

    /**
     * @brief setSprite provides the stickman object for the game
     * @param filename (non-suffixed) of the sprite images
     * @param extension of the image files
     * @param numImages
     */
    void setSprite(QString filename, QString extension, int numImages);

    /**
     * @brief addSoundtrack optional to call after the config has been provided
     */
    void addSoundtrack();

    /**
     * @brief ~GameBuilder virtual destructor
     */
    virtual ~GameBuilder();

    /**
     * @brief buildGame main build function
     * @return pointer to Game object
     */
    Game * buildGame();

private:
    Config config;
    Background background;
    Sprite sprite;
};

#endif // GAMEBUILDER_H
