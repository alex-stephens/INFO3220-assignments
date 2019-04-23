#pragma once

#include "gamedialog.h"

#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QDesktopWidget>
#include <QApplication>
#include <iostream>

#include "config.h"
#include "coordinate.h"
#include "background.h"
#include "pausedialog.h"
#include "startdialog.h"


class Stage1Game : public GameDialog {
public:
    explicit Stage1Game(QWidget *parent = 0);
    ~Stage1Game();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    //Functions to get paused state but also set the pause state
    void pause() { paused = true; }
    void unpause() { paused = false; }
    bool getPausedState() { return paused; }

private:
    QTimer *timer;
    Background background;
    int stickman_frame;
    int counter;
};
