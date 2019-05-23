#ifndef LIVES_H
#define LIVES_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>
#include "renderer.h"

class Lives {
public:
    Lives();

    void setLives(int num) { numLives = num; }
    void decrement();
    void render(Renderer &renderer);

private:
    int numLives;
    QPixmap digits[10];
};

#endif // LIVES_H
