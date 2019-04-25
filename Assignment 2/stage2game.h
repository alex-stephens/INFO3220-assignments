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


class Stage2Game : public GameDialog {
public:
    explicit Stage2Game(QWidget *parent = 0);
    ~Stage2Game();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

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
