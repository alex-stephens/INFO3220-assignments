#include "sprite.h"

#include <QDebug>

Sprite::Sprite(QString path_prefix, QString extension, unsigned int num_frames)
    : path_prefix(path_prefix),
      path_extension(path_extension),
      num_frames(num_frames),
      frame(1),
      frame_hold(10) { }

void Sprite::render(QPainter &painter) {

    update();

    QString path = path_prefix + QString::number(img_num) + extension;
    qDebug() << path;
    QPixmap stickman(path);

    painter.drawPixmap(QRect(50, 0, 50, 50), stickman);
}

void Sprite::update() {
    frame = (frame + 1) % (frame_hold * num_frames);
    img_num = 1 + (frame / frame_hold);
}
