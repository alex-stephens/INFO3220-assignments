#include "sprite.h"

#include <QDebug>

Sprite::Sprite()
    : size(10),
      filename_prefix(""),
      extension(""),
      num_frames(1),
      frame(1),
      frame_hold(1) {
}

Sprite::~Sprite() {}


Sprite::Sprite(Coordinate coordinate, unsigned int size, QString path_prefix, QString extension, unsigned int num_frames)
    : coordinate(coordinate),
      size(size),
      filename_prefix(path_prefix),
      extension(extension),
      num_frames(num_frames),
      frame(1),
      frame_hold(10) {

    height = size;
    width = size/2;

    coordinate.setYCoordinateToZero(height);
}

void Sprite::render(QPainter &painter) {

    update();
//    coordinate.setYCoordinateToZero(height/2);

    QString path = RESOURCES_PATH + filename_prefix + QString::number(img_num) + extension;
    QPixmap stickman(path);

//    painter.drawPixmap(QRect(coordinate.getQtRenderingXCoordinate()-width/2, coordinate.getQtRenderingYCoordinate()-height/2,
//                             width, height), stickman);

    qDebug() << coordinate.getQtRenderingYCoordinate();
    painter.drawPixmap(coordinate.getQtRenderingXCoordinate()-width/2, coordinate.getQtRenderingYCoordinate()-height/2,
                             width, height, stickman);
}

void Sprite::update() {
    frame = (frame + 1) % (frame_hold * num_frames);
    img_num = 1 + (frame / frame_hold);
}
