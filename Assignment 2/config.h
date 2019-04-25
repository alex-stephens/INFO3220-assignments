#pragma once

#include <QWidget>
#include <QDesktopWidget>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>
#include <iostream>
#include <string>
#include <vector>

#include "stickman.h"
#include "stage2stickman.h"
#include "obstacle.h"

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
    Stage2Stickman* getStickman() { return stickman; }
    int getWorldWidth() { return world_width; }
    int getWorldHeight() { return world_height; }
    int getBackgroundNumber() { return background_number; }

    //Setter functions
    void setWorldWidth(int width) { world_width = width; }
    void setWorldHeight(int height) { world_height = height; }
    void setBackgroundNumber(int number) { background_number = number; }
    void setStickman(Stage2Stickman *new_stickman) { stickman = new_stickman; }

    // Stage 2 getter functions
    bool getStage2Enable() { return stage2_enable; }
    std::vector<Obstacle>& getObstacles() { return obstacles; }

    // Stage 2 setter functions
    void setStage2Enable(bool val) { stage2_enable = val; }

protected:

private:

    static Config *config_instance;

    // Private so that it can not be called
    Config() {}

    int world_width;
    int world_height;
    int background_number;
    Stage2Stickman *stickman;

    // stage 2 member variables
    bool stage2_enable;
    int obstacle_height;
    int obstacle_width;
    int obstacle_spacing;
    std::vector<Obstacle> obstacles;
};

