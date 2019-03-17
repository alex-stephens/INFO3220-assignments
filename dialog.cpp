#include "dialog.h"
#include "ui_dialog.h"

//Dialog::Dialog(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::Dialog)
//{
//    ui->setupUi(this);
//    this->setStyleSheet("background-color: #82CAFF;");

//    this->update();
//}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
//    m_ball(Ball(Coordinate(20, 20, 600), 20, -9.8, 2.7, 17)),
    m_ball(Ball(Coordinate(20, 20, 600), 20, -9.8, 10, 17)),
    m_counter(0)
{
    ui->setupUi(this);
    this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setStyleSheet("background-color: #277edb;");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

void Dialog::keyPressEvent(QKeyEvent *event){
    int step = 20;
    if (event->key() == Qt::Key_Left){
        qDebug("left");
        m_ball.move(-step, 0);
    }
    else if (event->key() == Qt::Key_Right){
        qDebug("right");
        m_ball.move(step, 0);
    }
    else if (event->key() == Qt::Key_Up){
        qDebug("up");
        m_ball.move(0, step);
    }
    else if (event->key() == Qt::Key_Down){
        qDebug("down");
        m_ball.move(0, -step);
    }
}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    bool animation = true;
    if (animation) {
        // code for this exercise goes here

        QPainter painter(this);
        m_ball.render(painter, m_counter);
        m_counter++;

    }
    else {
        QPainter painter(this);

        // draw the sun
        QPen pen;
        pen.setWidth(10);
        pen.setColor(Qt::black);
        QBrush brush(Qt::yellow);

        painter.setPen (pen);
        painter.setBrush(brush);

        painter.drawEllipse(30, 30, 100, 100);

        // draw the house
        brush.setColor("#C36241");
        painter.setBrush(brush);
        pen.setWidth(1);

        QPolygon roof;
        roof.putPoints(0, 3, 250, 260, 290, 220, 330, 260);
        painter.drawPolygon(roof);

        brush.setColor("#835C3B");
        painter.setBrush(brush);

        QPolygon house;
        house.putPoints(0, 4, 260, 260, 260, 299, 320, 299, 320, 260);
        painter.drawPolygon(house);


    }
}

void Dialog::nextFrame()
{
    update();
}
