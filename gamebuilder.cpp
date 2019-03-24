#include "gamebuilder.h"

GameBuilder::GameBuilder(Config config)
    : config(config)
{
    setConfig(config);
}

void GameBuilder::setConfig(Config c) {
    config = c;

    // once the config is set, the background can be constructed
    background = Background(config.getBackgroundFile(), config.getVelocity());
}

void GameBuilder::setSprite(QString filename, QString extension, int numImages) {
    sprite = Sprite(Coordinate(config.getPosition(), config.getSize()/2, WINDOW_HEIGHT),
                    config.getSize(), filename, extension, numImages);
}

Game * GameBuilder::buildGame() {
    return new Game(background, sprite);
}



//sprite(Coordinate(config.getPosition(), config.getSize()/2, WINDOW_HEIGHT), config.getSize(),"sprite_", ".gif", 3)
