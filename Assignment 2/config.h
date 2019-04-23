#pragma once

#include <QWidget>
#include <QDesktopWidget>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>
#include <iostream>
#include <string>

#include "stickman.h"

class Config {

public:

    static Config *config() {

        if (!config_instance) { // Only allow one instance of class to be generated.
            config_instance = new Config;
        }

        return config_instance;
    }

    ~Config();

    virtual void setupConfig();

    //Getter functions
    Stickman* getStickman() { return stickman; }
    int getWorldWidth() { return world_width; }
    int getWorldHeight() { return world_height; }
    int getBackgroundNumber() { return background_number; }

    //Setter functions
    void setWorldWidth(int width) { world_width = width; }
    void setWorldHeight(int height) { world_height = height; }
    void setBackgroundNumber(int number) { background_number = number; }
    void setStickman(Stickman *new_stickman) { stickman = new_stickman; }

protected:

private:

    static Config *config_instance;

    // Private so that it can not be called
    Config() {}

    int world_width;
    int world_height;
    int background_number;
    Stickman *stickman;
};

