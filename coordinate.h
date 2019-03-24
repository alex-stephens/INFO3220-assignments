#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdlib.h>

class Coordinate
{
public:
    Coordinate();

    Coordinate(
        int xCoordinate,
        int yCoordinate,
        unsigned int frameHeight);

    int getQtRenderingXCoordinate();
    int getQtRenderingYCoordinate();

    int getXCoordinate();
    int getYCoordinate();


    void changeInXCoordinate(int change);
    void changeInYCoordinate(int change);

    void setYCoordinateToZero(int offset);

    unsigned int getFrameHeight();

    ~Coordinate() {

    }

private:
    int xCoordinate;
    int yCoordinate;
    unsigned int m_frameHeight;
};

#endif // COORDINATE_H
