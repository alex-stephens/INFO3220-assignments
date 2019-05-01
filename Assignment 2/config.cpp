#include "config.h"

Config::~Config() {
    std::cout << "Deleted Stickman" << std::endl;
}

void Config::setupConfig() {

    //Set up the frame size of the game
    Config::config()->setWorldWidth(1000);
    Config::config()->setWorldHeight(600);

    std::string config_size = "normal";
    int config_position = 0;

    QFile config_file(":config/config.txt");

    //Open the config file
    if (config_file.open(QIODevice::ReadOnly)) {

        QTextStream buffer(&config_file);

        while (!buffer.atEnd()) {

            QString line = buffer.readLine();

            QStringList split_line = line.split(":", QString::SkipEmptyParts);

            QString element = split_line.at(1);

            if (split_line.first() =="Size") {

                if (element.toStdString() != "tiny" && element.toStdString() != "normal" &&
                        element.toStdString() != "large" && element.toStdString() != "giant") {
                    std::cerr << "Not a defined size in config file, please make it a valid size" << std::endl <<
                                 "Valid sizes are: tiny, normal, large, giant" << std::endl;
                    return;
                }

                config_size = element.toStdString();
            }

            else if (split_line.first() == "Position") {

                if (element.toInt() < 0 || element.toInt() > getWorldWidth()) {
                    std::cerr << "Position is out of bounds. Please make it a valid position" << std::endl <<
                                 "[0 <= position <= " << getWorldWidth() << "]" << std::endl;
                    return;
                }

                config_position = element.toInt();
            }

            else if (split_line.first() == "xVelocity") {
                background_velocity = element.toDouble();
            }

            else if (split_line.first() == "Background") {

                if (element.toInt() < 1 || element.toInt() > 2) {
                    std::cerr << "Background does not exist. Please make it a valid background" << std::endl <<
                                 "[1 <= background_number <= 2]" << std::endl;
                    return;
                }

                Config::config()->setBackgroundNumber(element.toInt());
            }

            else if (split_line.first() == "Stage2") {
                if (element.toStdString() != "true" && element.toStdString() != "false") {
                    std::cerr << "Stage2 must be either true (enabled) or false (disabled)" << std::endl;
                    return;
                }
                else if (element.toStdString() == "true") {
                    Config::config()->setStage2Enable(true);
                }
                else {
                    Config::config()->setStage2Enable(false);
                }
            }
            else if (split_line.first() == "ObstacleHeight") {
                obstacle_height = element.toInt();
            }
            else if (split_line.first() == "ObstacleWidth") {
                obstacle_width = element.toInt();
            }
            else if (split_line.first() == "ObstacleSpacing") {
                if (element.toInt() < 0) {
                    std::cerr << "Obstacles must be non-overlapping in the horizontal direction" << std::endl;
                    return;
                }
                obstacle_spacing = element.toInt();
            }
            else if (split_line.first() == "Obstacles") {
                if (obstacle_height == 0 || obstacle_width == 0 || obstacle_spacing == 0) {
                    std::cerr << "Object parameters (height, width, spacing) must be provided before object locations" << std::endl;
                }

                QStringList split_line = line.split(":", QString::SkipEmptyParts);
                QStringList obstacles_strings = split_line.at(1).split(",", QString::SkipEmptyParts);

                for (QString s : obstacles_strings) {
                    obstacles.push_back(s.toInt());
                }
            }

        }

        config_file.close();
    } else {
        std::cerr << "Config file not found" << std::endl;
    }

    //Create the stickman, given the parameters from the config file
//    Config::config()->setStickman(new MotionDecorator(new Stage2Stickman(config_size, config_position, background_velocity)));
    Config::config()->setStickman(new Stage2Stickman(config_size, config_position, background_velocity));


    // check what obstacles were found
//    std::cout << "OBSTACLES:" << std::endl;
//    for (Obstacle i : obstacles) {
//        std::cout << i.getCoordinate().getXCoordinate() << ", " << i.getCoordinate().getYCoordinate() << std::endl;
//    }
}

