#include <QApplication>
#include <iostream>
#include <QSound>

#include "config.h"
#include "startdialog.h"
#include "stage1gamefactory.h"

//Allocating and initializing Config static data member. The pointer is being allocated - not the object itself
Config *Config::config_instance = 0;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //Sets up the config class for all files to use
    Config::config()->setupConfig();

    //Infinite loop of background music
    QSound sound(":sound/background_music.wav");
    sound.setLoops(-1);
    sound.play();

    StartDialog start_dialog(new Stage1GameFactory());
    start_dialog.setWindowTitle("Main Menu");
    start_dialog.show();

    return a.exec();
}
