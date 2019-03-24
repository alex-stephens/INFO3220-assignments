#include "dialog.h"

#include "ui_dialog.h"
#include "pause.h"

#include <iostream>
#include <vector>
#include <QDir>
#include <QLabel>
#include <QMovie>
#include <QDebug>


Dialog::Dialog(Config config) :
    QDialog(),
    ui(new Ui::Dialog),
    background(config.getBackgroundFile(), config.getVelocity()),
    sprite(Sprite(Coordinate(config.getPosition(), config.getSize()/2, WINDOW_HEIGHT), config.getSize(),"sprite_", ".gif", 3))
{
    ui->setupUi(this);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    backgroundOffset = 0;


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

void Dialog::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        qDebug("left");
//        ball.setXVelocity(-5);
    }
    else if (event->key() == Qt::Key_Right){
        qDebug("right");
//        ball.setXVelocity(5);
    }
    else if (event->key() == Qt::Key_Up){
        qDebug("up");
//        ball.jump();
    }
    else if (event->key() == Qt::Key_Down){
        qDebug("down");
//        ball.move(0, -step);
    }
    else if (event->key() == Qt::Key_P){
        paused = !paused;

    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    if (paused){
        Pause pause("pause_img.png");
        pause.render(painter);
    }
    else {
        background.render(painter);
        sprite.render(painter);
    }

}

void Dialog::nextFrame() {
    update();
}
