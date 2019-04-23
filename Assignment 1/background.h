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

    /**
     * @brief the Background default constructor
     */
    Background();

    /**
     * @brief Background constructor
     * @param filename name of background file within resources directory
     * @param speed at which the background moves
     */
    Background(QString filename, int speed);

    /**
     * @brief render update and display the background image
     * @param painter reference to the game dialog painter
     */
    void render(QPainter &painter);

    /**
     * @brief update shift the background offset based on the velocity
     */
    void update();

    /**
     * @brief ~Background destructor
     */
    virtual ~Background();

    /**
     * @brief setFilename set the background source filename
     * @param filename
     */
    void setFilename(QString filename);

    /**
     * @brief setNightModeFilename
     * @param filename
     */
    void setNightModeFilename(QString filename);

    /**
     * @brief toggleNightMode switch between day and night mode
     */
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
