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

    void setFilename(QString filename);
    void setNightModeFilename(QString filename);
    void toggleNightMode();

private:
    QString filename;

    int speed;
    int offset;

    bool nightMode = false;
    QString dayModeFilename;
    QString nightModeFilename;
};

#endif // BACKGROUND_H
