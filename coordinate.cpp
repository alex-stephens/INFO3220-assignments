#include "coordinate.h"

Coordinate::Coordinate(unsigned int x,unsigned int y, unsigned int frameHeight) :
    m_xCoordinate(x),
    m_yCoordinate(y),
    m_frameHeight(frameHeight)
{

}

unsigned int Coordinate::getQtRenderingXCoordinate() {
    return m_xCoordinate;
}

unsigned int Coordinate::getQtRenderingYCoordinate()
{
    return m_frameHeight - m_yCoordinate;
}

void Coordinate::changeInXCoordinate(int change) {
    m_xCoordinate += change;
}

void Coordinate::changeInYCoordinate(int change) {
    m_yCoordinate += change;
}

void Coordinate::setYCoordinateToZero(int offset) {
    m_yCoordinate = offset;
}

unsigned int Coordinate::getFrameHeight() {
    return m_frameHeight;
}
