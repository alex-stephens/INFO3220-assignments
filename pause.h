#ifndef PAUSE_H
#define PAUSE_H

#include "graphics.h"
#include "params.h"

#include <QString>


class Pause : public Graphics
{
public:
    Pause(QString filename);


    void render(QPainter &painter);

    ~Pause() {

    }

private:
    QString filename;
};

#endif // PAUSE_H


