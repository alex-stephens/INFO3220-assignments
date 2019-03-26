#include "game.h"

#include "gamebuilder.h"
#include "params.h"

#include <QApplication>
#include <iostream>
#include <QJsonDocument>
#include <QtXml>
#include <QFile>

int main(int argc, char *argv[])
{
    QString config_file = "config.xml";
    try {

        Config config(RESOURCES_PATH + config_file);

        GameBuilder gameBuilder(config);
        gameBuilder.setSprite("sprite_", ".gif", 3);

        QApplication a(argc, argv);
        Game * game = gameBuilder.buildGame();
        game->show();

        return a.exec();

    } catch (char const* s) {
        std::cerr << "Invalid configuration file provided";
    }


}
