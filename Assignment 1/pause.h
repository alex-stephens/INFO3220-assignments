#ifndef PAUSE_H
#define PAUSE_H

#include "graphics.h"
#include "params.h"

#include <QString>


class Pause : public Graphics
{
public:
    /**
     * @brief Pause constructor from image filename
     * @param filename
     */
    Pause(QString filename);

    /**
     * @brief render show a frame of the pause screen
     * @param painter game dialog window painter
     */
    void render(QPainter &painter);

    /**
     * @brief ~Pause virtual destructor
     */
    virtual ~Pause();

private:
    QString filename;
};

#endif // PAUSE_H


