#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QPainter>

class Graphics
{
public:
    /**
     * @brief ~Graphics virtual destructor
     */
    virtual ~Graphics();

    /**
     * @brief render
     * @param painter for dialog window
     */
    virtual void render(QPainter &painter) = 0;
};

#endif // GRAPHICS_H
