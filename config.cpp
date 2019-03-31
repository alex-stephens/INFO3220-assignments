#include "config.h"

Config::~Config() {}

QString Config::getBackgroundFile() {
    return background_file;
}


QString Config::getNightBackgroundFile() {
    return night_background_file;
}

QString Config::getSoundtrack() {
    return soundtrack;
}

unsigned int Config::getSize() {
    return size;
}

int Config::getPosition() {
    return position;
}

int Config::getVelocity() {
    return velocity;
}

Config::Config(QString path) {

    QDomDocument dom;

    if (!isValidFile(path)){
        printf ("Invalid configuration file path");
        exit (EXIT_FAILURE);
    }

    QFile f(path);

    // Set data into the QDomDocument before processing
    dom.setContent(&f);
    f.close();

    // Extract the root markup
    QDomElement root = dom.documentElement();

    // extract all configuration parameters, and check for invalid parameters
    for (int i = 0; i < root.childNodes().count(); i++){

        QDomNode child = root.childNodes().at(i);

        if (child.nodeName() == "size"){
            QString s = child.firstChild().toText().data();
            size = SIZE[s];
        }

        else if (child.nodeName() == "position") {
            position = child.firstChild().toText().data().toInt();
        }

        else if (child.nodeName() == "velocity") {
            velocity = child.firstChild().toText().data().toInt();
        }

        else if (child.nodeName() == "background") {
            background_file = child.firstChild().toText().data();
        }

        else if (child.nodeName() == "nightbackground") {
            night_background_file = child.firstChild().toText().data();
        }

        else if (child.nodeName() == "soundtrack") {
            soundtrack = child.firstChild().toText().data();
        }

        else {
            // doesn't stop the program, but print a warning
            printf("Invalid configuration parameter found in file");
        }
    }
}

bool Config::isValidFile(QString path) {
    QFileInfo f(path);
    return (f.exists() && f.isFile());
}
