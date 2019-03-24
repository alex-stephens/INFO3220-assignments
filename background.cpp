#include "background.h"

Background::Background()
    : filename(""),
      speed(0),
      offset(0) { }

Background::Background(QString path, int speed)
    : filename(path),
      speed(speed),
      offset(0) { }

void Background::render(QPainter &painter) {
    QString fullpath = RESOURCES_PATH + filename;
    QPixmap bkgnd(fullpath);

    update();

    painter.drawPixmap(QPoint((-offset)%WINDOW_WIDTH + WINDOW_WIDTH,0), bkgnd);
    painter.drawPixmap(QPoint((-offset)%WINDOW_WIDTH,0), bkgnd);
}

void Background::update() {
    offset += speed;
}
