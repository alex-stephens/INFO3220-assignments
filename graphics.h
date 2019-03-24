#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QPainter>

class Graphics
{
public:
    virtual ~Graphics() { }
    virtual void render(QPainter &painter) = 0;
};

#endif // GRAPHICS_H
