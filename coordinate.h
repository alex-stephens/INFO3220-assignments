#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdlib.h>

class Coordinate
{
public:
    /**
     * @brief Coordinate default constructor
     */
    Coordinate();

    /**
     * @brief Coordinate system constructor
     * @param xCoordinate
     * @param yCoordinate
     * @param frameHeight
     */
    Coordinate(
        int xCoordinate,
        int yCoordinate,
        unsigned int frameHeight);

    /**
     * @brief getQtRenderingXCoordinate
     * @return x coordinate in Qt coordinates
     */
    int getQtRenderingXCoordinate();

    /**
     * @brief getQtRenderingYCoordinate
     * @return y coordinate in Qt coordinates
     */
    int getQtRenderingYCoordinate();

    /**
     * @brief getXCoordinate
     * @return x coordinate in cartesian coordinates
     */
    int getXCoordinate();

    /**
     * @brief getYCoordinate
     * @return y coordinate in cartesian coordinates
     */
    int getYCoordinate();

    /**
     * @brief changeInXCoordinate
     * @param update to x coordinate
     */
    void changeInXCoordinate(int change);

    /**
     * @brief changeInXCoordinate
     * @param update to y coordinate
     */
    void changeInYCoordinate(int change);

    /**
     * @brief setYCoordinateToZero
     * @param offset due to object size
     */
    void setYCoordinateToZero(int offset);

    /**
     * @brief getFrameHeight
     * @return frame height value
     */
    unsigned int getFrameHeight();

    /**
     * @brief ~Coordinate destructor
     */
    virtual ~Coordinate();

private:
    int xCoordinate;
    int yCoordinate;
    unsigned int m_frameHeight;
};

#endif // COORDINATE_H
