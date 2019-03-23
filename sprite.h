#ifndef SPRITE_H
#define SPRITE_H

#include "params.h"

#include <QString>
#include <QPixmap>
#include <QPainter>

class Sprite
{
public:
    Sprite(QString path_prefix, QString path_extension, unsigned int num_frames);

    void render(QPainter &painter);
    void update();

    ~Sprite() {

    }

private:
    QString path_prefix;
    QString extension;

    const unsigned int num_frames;

    unsigned int img_num;
    unsigned int frame;

    unsigned int frame_hold;
};

#endif // SPRITE_H
