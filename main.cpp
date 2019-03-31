#include "game.h"

#include "gamebuilder.h"
#include "params.h"
#include "soundtrack.h"

#include <QApplication>
#include <iostream>
#include <QJsonDocument>
#include <QtXml>
#include <QFile>
#include <QSound>

int main(int argc, char *argv[]) {
    QString config_file = "config.xml";

    Config config(RESOURCES_PATH + config_file);

    GameBuilder gameBuilder(config);
    gameBuilder.setSprite("sprite_", ".gif", 3);

    QApplication a(argc, argv);
    Game * game = gameBuilder.buildGame();

    game->setSoundtrack(config.getSoundtrack());
    game->playSoundtrack();

    game->show();

    return a.exec();
}
