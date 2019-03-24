#include "background.h"

Background::Background()
    : path(""),
      speed(0),
      offset(0) { }

Background::Background(QString path, int speed)
    : path(path),
      speed(speed),
      offset(0) { }

void Background::render(QPainter &painter) {
    QPixmap bkgnd(path);

    update();

    painter.drawPixmap(QPoint((-offset)%WINDOW_WIDTH + WINDOW_WIDTH,0), bkgnd);
    painter.drawPixmap(QPoint((-offset)%WINDOW_WIDTH,0), bkgnd);
}

void Background::update() {
    offset += speed;
}
