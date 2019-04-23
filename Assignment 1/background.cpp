#include "background.h"

Background::Background()
    : filename(""),
      speed(0),
      offset(0) { }

Background::~Background() {}

Background::Background(QString f, int speed)
    : filename(f),
      speed(speed),
      offset(0),
      dayModeFilename(f) { }

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

void Background::setFilename(QString f) {
    filename = f;
    dayModeFilename = f;
}

void Background::setNightModeFilename(QString f) {
    nightModeFilename = f;
}

void Background::toggleNightMode() {
    nightMode ^= 1;
    if (nightMode && nightModeFilename.size() > 0) {
        filename = nightModeFilename;
    }
    else {
        filename = dayModeFilename;
    }
}
