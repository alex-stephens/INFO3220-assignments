#include "dialog.h"

#include "ui_dialog.h"

#include <iostream>
#include <vector>
#include <QDir>
#include <QLabel>
#include <QMovie>
#include <QDebug>


Dialog::Dialog(Config config) :
    QDialog(),
    ui(new Ui::Dialog),
    background("/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/resources/" + config.getBackgroundFile(),
               config.getVelocity()),
    sprite(Sprite(Coordinate(config.getPosition(),config.getSize()/2, WINDOW_HEIGHT), config.getSize(),
            "/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/resources/sprite_", ".gif", 3))
{
    ui->setupUi(this);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    backgroundOffset = 0;

//    QString path = "/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/resources/" + config.getBackgroundFile();
//    background = Background(path, config.getVelocity());


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

void Dialog::keyPressEvent(QKeyEvent *event){
    int step = 20;
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
}

Dialog::~Dialog()
{
    delete ui;
}


//void Dialog::updateBackground(int shift) {
//    backgroundOffset += shift;
//}

//void Dialog::setBackground(QString path, int offset) {
//    QPixmap bkgnd(path);

//    this->updateBackground(BACKGROUND_SPEED);

//    QPainter painter(this);
//    painter.drawPixmap(QPoint((-backgroundOffset)%WINDOW_WIDTH + WINDOW_WIDTH,0), bkgnd);
//    painter.drawPixmap(QPoint((-backgroundOffset)%WINDOW_WIDTH,0), bkgnd);
//}


//void Dialog::drawSprite(QString path) {
//    QPixmap sprite(path);

//    QPainter painter(this);
////    painter.drawPixmap(QPoint(200, 200), sprite);
//    painter.drawPixmap(QRect(50, 0, 50, 50), sprite);
//}

void Dialog::paintEvent(QPaintEvent *event) {

//    QString path("/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/resources/background.png");
//    setBackground(path, backgroundOffset);
    QPainter painter(this);
    background.render(painter);

//    QString sprite_path("/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment1/resources/sprite_1.gif");
//    drawSprite(sprite_path);

    sprite.render(painter);
//    ball.render(painter);
}

void Dialog::nextFrame() {
    update();
}
