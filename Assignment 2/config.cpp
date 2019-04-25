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
    double config_xvelocity = 0.0;

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
                config_xvelocity = element.toDouble();
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
                obstacle_spacing = element.toInt();
            }
            else if (split_line.first() == "Obstacles") {
                QStringList split_line = line.split(":", QString::SkipEmptyParts);
                QStringList obstacles_string = split_line.at(1).split(",", QString::SkipEmptyParts);
                std::vector<int> obstacles;
                for (QString o : obstacles_string) {
                    obstacles.push_back(o.toInt());
                }
                for (int i : obstacles) {
                    std::cout << i << std::endl;
                }
                std::cout << obstacles_string.at(2).toInt() << std::endl;
            }

        }

        config_file.close();
    } else {
        std::cerr << "Config file not found" << std::endl;
    }

    //Create the stickman, given the parameters from the config file
    Config::config()->setStickman(new Stage2Stickman(config_size, config_position, config_xvelocity));
    std::cout << "creating stage 1 stickman" << std::endl;
}

