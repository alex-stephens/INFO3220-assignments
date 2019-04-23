#ifndef GAME_H
#define GAME_H

#include "background.h"
#include "params.h"
#include "sprite.h"
#include "config.h"
#include "ui_dialog.h"
#include "pause.h"

#include <iostream>
#include <vector>
#include <QDialog>
#include <QTimer>
#include <QDir>
#include <QLabel>
#include <QMovie>
#include <QDebug>
#include <QKeyEvent>
#include <QSound>

namespace Ui {
class Dialog;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Game main constructor
     * @param background used for the dialog window
     * @param sprite stickman animation
     */
    Game(Background background, Sprite sprite);

    /**
     * @brief Game config-based constructor
     * @param config file used to set up the background and sprite
     */
    explicit Game(Config config);

    /**
     * @brief ~Game virtual destructor
     */
    virtual ~Game();

    /**
     * @brief keyPressEvent function to process key presses
     * @param event encoding which key was pressed
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief updateBackground horizontally shift the background
     * @param shift the background by this many pixels
     */
    void updateBackground(int shift);

    /**
     * @brief setBackground set the background image and offste
     * @param path to background image
     * @param offset in pixels
     */
    void setBackground(QString path, int offset);

    /**
     * @brief addSoundtrack
     * @param soundtrack object
     */
    void setSoundtrack(QString s);

    void playSoundtrack();

    void pauseSoundtrack();

public slots:
    /**
     * @brief nextFrame
     */
    void nextFrame();

protected:
    /**
     * @brief paintEvent
     * @param event
     */
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Background background;
    Sprite sprite;
    QMovie *movie;

    int backgroundOffset = 0;
    bool paused = false;

    QSound * soundtrack;
};



#endif // GAME_H
