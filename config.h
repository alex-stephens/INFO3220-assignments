#ifndef CONFIG_H
#define CONFIG_H

#include "params.h"

#include <QtXml>
#include <QFile>
#include <QString>
#include <iostream>
#include <stdexcept>


class Config
{
public:
    Config(QString path);

    ~Config() {

    }

    int getSize();
    int getPosition();
    int getVelocity();
    QString getBackgroundFile();


private:
    int size;
    int position;
    int velocity;
    QString background_file;
};

#endif // CONFIG_H
