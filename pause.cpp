#include "pause.h"

Pause::Pause(QString filename)
    : filename(filename) { }

Pause::~Pause() {}

void Pause::render(QPainter &painter) {
    QString fullpath = RESOURCES_PATH + filename;
    QPixmap pause_text(fullpath);

    painter.drawPixmap(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, pause_text);
}
