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

    /**
     * @brief Sprite default constructor
     */
    Sprite();

    /**
     * @brief Sprite constructor
     * @param coordinate of sprite
     * @param size in pixels
     * @param filename_prefix frames will be in filename_prefix1.ext, filename_prefix2.ext, ...
     * @param path_extension specifies the extension .ext for the frames
     * @param num_frames total number of frames of the sprite image
     */
    Sprite(Coordinate coordinate, unsigned int size, QString filename_prefix, QString path_extension, unsigned int num_frames);

    /**
     * @brief render update and render the sprite in the current dialog window
     * @param painter for the dialog window
     */
    void render(QPainter &painter);

    /**
     * @brief update the current state of the sprite
     */
    void update();

    /**
     * @brief ~Sprite virtual destructor
     */
    virtual ~Sprite();

private:
    QString filename_prefix;
    QString extension;

    Coordinate coordinate;

    unsigned int num_frames;

    unsigned int img_num;
    unsigned int frame;

    unsigned int frame_hold;

    unsigned int size;
    unsigned int height;
    unsigned int width;

};

#endif // SPRITE_H
