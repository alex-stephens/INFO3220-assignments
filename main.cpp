#include "dialog.h"

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

        QApplication a(argc, argv);
        Dialog w(config);
        w.show();

        return a.exec();

    } catch (char const* s) {
        std::cout << "Invalid configuration file provided";
    }


}
