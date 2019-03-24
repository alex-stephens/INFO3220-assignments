#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "params.h"
#include "graphics.h"

#include <QString>
#include <QPixmap>
#include <QPainter>

class Background : public Graphics
{
public:
    Background();
    Background(QString filename, int speed);


    void render(QPainter &painter);
    void update();

    ~Background() {

    }

private:
    QString filename;

    int speed;
    int offset;
};

#endif // BACKGROUND_H
