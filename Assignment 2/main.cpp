#include <QApplication>
#include <iostream>
#include <QSound>
#include <QSoundEffect>

#include "config.h"
#include "startdialog.h"
#include "stage1gamefactory.h"
#include "stage2gamefactory.h"

//Allocating and initializing Config static data member. The pointer is being allocated - not the object itself
Config *Config::config_instance = 0;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //Sets up the config class for all files to use
    Config::config()->setupConfig();

    //Infinite loop of background music
    QSoundEffect sound;
    sound.setSource(QUrl::fromLocalFile(":sound/background_music.wav"));
    sound.setLoopCount(QSoundEffect::Infinite);
    sound.setVolume(0.25);
    sound.play();

    StartDialog start_dialog(new Stage2GameFactory);

    start_dialog.setWindowTitle("Main Menu");
    start_dialog.show();

    return a.exec();
}
