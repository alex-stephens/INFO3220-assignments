#include "ball.h"
#include "dialog.h"

Ball::Ball(Coordinate coordinate) :
    m_coordinate(coordinate),
    m_radius(30),
    m_gravity(-9.81),
    m_xVelocity(1),
    m_yVelocity(1)
{

}

Ball::Ball(Coordinate coordinate,
           unsigned int radius) :
    m_coordinate(coordinate),
    m_radius(radius),
    m_gravity(-9.81),
    m_xVelocity(1),
    m_yVelocity(1)
{

}

Ball::Ball(Coordinate coordinate,
           unsigned int radius,
           double gravity,
           double xVelocity,
           double yVelocity) :
    m_coordinate(coordinate),
    m_radius(radius),
    m_gravity(gravity),
    m_xVelocity(xVelocity),
    m_yVelocity(yVelocity)
{

}


bool Ball::verticalCollision() {
    return m_coordinate.getQtRenderingYCoordinate() >
        (signed int) (m_coordinate.getFrameHeight() - (signed int) m_radius);
}

bool Ball::horizontalCollision() {
return m_coordinate.getQtRenderingXCoordinate() < m_radius
        || m_coordinate.getQtRenderingXCoordinate() > WINDOW_WIDTH - m_radius;
}

unsigned int Ball::getRadius() {
    return m_radius;
}

void Ball::move(int x, int y) {
    m_coordinate.changeInXCoordinate(x);
    m_coordinate.changeInYCoordinate(y);
}

void Ball::render(QPainter &painter, unsigned int time)
{
    if (verticalCollision()) {
        m_coordinate.setYCoordinateToZero(this->getRadius());
        // velocity decreases after hitting the ground
        m_yVelocity *= -0.8;

        m_xVelocity *= 0.9;
    }

    if (horizontalCollision()) {
        m_xVelocity *= -1;
    }

    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( Qt::yellow ) );
    painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - int(m_radius),
        m_coordinate.getQtRenderingYCoordinate() - int(m_radius),
        m_radius * 2,
        m_radius * 2);
}

