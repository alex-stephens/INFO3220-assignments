#include "game.h"

#include "gamebuilder.h"

#include <QApplication>
#include <iostream>
#include <QJsonDocument>
#include <QtXml>
#include <QFile>

int main(int argc, char *argv[])
{
    QString config_file = "/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/config.xml";
    try {

        Config config(config_file);

        GameBuilder gameBuilder(config);
        gameBuilder.setSprite("sprite_", ".gif", 3);

        QApplication a(argc, argv);
        Game * game = gameBuilder.buildGame();
        game->show();

//        QApplication a(argc, argv);
//        Game game(config);
//        game.show();

        return a.exec();

    } catch (char const* s) {
        std::cerr << "Invalid configuration file provided";
    }


}
