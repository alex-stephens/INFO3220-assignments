#include "sprite.h"

#include <QDebug>

Sprite::Sprite(Coordinate coordinate, unsigned int size, QString path_prefix, QString extension, unsigned int num_frames)
    : coordinate(coordinate),
      size(size),
      path_prefix(path_prefix),
      extension(extension),
      num_frames(num_frames),
      frame(1),
      frame_hold(10) {

    height = size;
    width = size/2;

    coordinate.setYCoordinateToZero(height);
}

void Sprite::render(QPainter &painter) {

    updateImage();
//    coordinate.setYCoordinateToZero(height/2);

    QString path = path_prefix + QString::number(img_num) + extension;
    QPixmap stickman(path);

//    painter.drawPixmap(QRect(coordinate.getQtRenderingXCoordinate()-width/2, coordinate.getQtRenderingYCoordinate()-height/2,
//                             width, height), stickman);

    qDebug() << coordinate.getQtRenderingYCoordinate();
    painter.drawPixmap(coordinate.getQtRenderingXCoordinate()-width/2, coordinate.getQtRenderingYCoordinate()-height/2,
                             width, height, stickman);
}

void Sprite::updateImage() {
    frame = (frame + 1) % (frame_hold * num_frames);
    img_num = 1 + (frame / frame_hold);
}
