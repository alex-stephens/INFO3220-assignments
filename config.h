#ifndef CONFIG_H
#define CONFIG_H

#include "params.h"

#include <QtXml>
#include <QFile>
#include <QString>
#include <iostream>
#include <stdexcept>
#include <QFileInfo>


class Config
{
public:
    Config(QString path);

    ~Config() {

    }

    unsigned int getSize();
    int getPosition();
    int getVelocity();
    QString getBackgroundFile();
    QString getNightBackgroundFile();


private:

    bool isValidFile(QString path);

    unsigned int size;
    int position;
    int velocity;
    QString background_file;
    QString night_background_file;
};

#endif // CONFIG_H
