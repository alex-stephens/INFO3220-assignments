#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "params.h"

#include <QString>
#include <QPixmap>
#include <QPainter>

class Background
{
public:
    Background();
    Background(QString path, int speed);


    void render(QPainter &painter);
    void update();

    ~Background() {

    }

private:
    QString path;

    int speed;
    int offset;
};

#endif // BACKGROUND_H
