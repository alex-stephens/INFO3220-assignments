#ifndef SPRITE_H
#define SPRITE_H

#include "params.h"
#include "coordinate.h"
#include "graphics.h"

#include <QString>
#include <QPixmap>
#include <QPainter>


class Sprite : public Graphics
{
public:
    Sprite(Coordinate coordinate, unsigned int size, QString filename_prefix, QString path_extension, unsigned int num_frames);

    void render(QPainter &painter);
    void update();

    ~Sprite() {

    }

private:
    QString filename_prefix;
    QString extension;

    Coordinate coordinate;

    const unsigned int num_frames;

    unsigned int img_num;
    unsigned int frame;

    unsigned int frame_hold;

    unsigned int size;
    unsigned int height;
    unsigned int width;

};

#endif // SPRITE_H
