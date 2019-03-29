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
    /**
     * @brief Config path-based constructor
     * @param path to config file
     */
    Config(QString path);

    /**
     * @brief ~Config destructor
     */
    virtual ~Config();

    /**
     * @brief getSize
     * @return size parameter
     */
    unsigned int getSize();

    /**
     * @brief getPosition
     * @return position parameter
     */
    int getPosition();

    /**
     * @brief getVelocity
     * @return velocity parameter
     */
    int getVelocity();

    /**
     * @brief getBackgroundFile
     * @return background file parameter
     */
    QString getBackgroundFile();

    /**
     * @brief getNightBackgroundFile
     * @return night background file parameter
     */
    QString getNightBackgroundFile();

    /**
     * @brief getSoundtrack
     * @return soundtrack file parameter (must use .wav format)
     */
    QString getSoundtrack();


private:

    bool isValidFile(QString path);
    unsigned int size;
    int position;
    int velocity;

    QString background_file;
    QString night_background_file;
    QString soundtrack;
};

#endif // CONFIG_H
