#include "coordinate.h"

Coordinate::Coordinate(int x,int y, unsigned int frameHeight) :
    xCoordinate(x),
    yCoordinate(y),
    m_frameHeight(frameHeight)
{

}

int Coordinate::getQtRenderingXCoordinate() {
    return xCoordinate;
}

int Coordinate::getQtRenderingYCoordinate()
{
    return m_frameHeight - yCoordinate;
}

int Coordinate::getXCoordinate() {
    return xCoordinate;
}

int Coordinate::getYCoordinate()
{
    return yCoordinate;
}

void Coordinate::changeInXCoordinate(int change) {
    xCoordinate += change;
}

void Coordinate::changeInYCoordinate(int change) {
    yCoordinate += change;
}

void Coordinate::setYCoordinateToZero(int offset) {
    yCoordinate = offset;
}

unsigned int Coordinate::getFrameHeight() {
    return m_frameHeight;
}
