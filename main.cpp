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

int main(int argc, char *argv[])
{
    QString config_file = "config.xml";
    try {

        Config config(RESOURCES_PATH + config_file);

        GameBuilder gameBuilder(config);
        gameBuilder.setSprite("sprite_", ".gif", 3);

        QApplication a(argc, argv);
        Game * game = gameBuilder.buildGame();

        game->setSoundtrack("/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/resources/music.wav");
        game->playSoundtrack();

        game->show();

        return a.exec();

    } catch (char const* s) {
        std::cerr << "Invalid configuration file provided";
    }


}
