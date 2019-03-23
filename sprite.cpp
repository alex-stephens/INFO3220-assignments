#include "sprite.h"

#include <QDebug>

Sprite::Sprite(Coordinate coordinate, QString path_prefix, QString extension, unsigned int num_frames)
    : coordinate(coordinate),
      path_prefix(path_prefix),
      extension(extension),
      num_frames(num_frames),
      frame(1),
      frame_hold(10) { }

void Sprite::render(QPainter &painter) {

    updateImage();

    QString path = path_prefix + QString::number(img_num) + extension;
    QPixmap stickman(path);

    painter.drawPixmap(QRect(coordinate.getQtRenderingXCoordinate(), coordinate.getQtRenderingYCoordinate(), 50, 50), stickman);
}

void Sprite::updateImage() {
    frame = (frame + 1) % (frame_hold * num_frames);
    img_num = 1 + (frame / frame_hold);
}
