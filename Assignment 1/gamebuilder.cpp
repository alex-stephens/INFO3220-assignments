#include "gamebuilder.h"

GameBuilder::GameBuilder(Config config)
    : config(config)
{
    setConfig(config);
}

GameBuilder::~GameBuilder() {}

void GameBuilder::setConfig(Config c) {
    config = c;

    // once the config is set, the background can be constructed
    background = Background(config.getBackgroundFile(), config.getVelocity());
    background.setNightModeFilename(config.getNightBackgroundFile());

}

void GameBuilder::setSprite(QString filename, QString extension, int numImages) {
    sprite = Sprite(Coordinate(config.getPosition(), config.getSize()/2, WINDOW_HEIGHT),
                    config.getSize(), filename, extension, numImages);
}

Game * GameBuilder::buildGame() {
    return new Game(background, sprite);
}
