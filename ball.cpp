#include "ball.h"
#include "dialog.h"
#include <QDebug>

Ball::Ball(Coordinate coordinate) :
    coordinate(coordinate),
    radius(30),
    gravity(-9.81),
    xVelocity(1),
    yVelocity(1)
{

}

Ball::Ball(Coordinate coordinate,
           unsigned int radius) :
    coordinate(coordinate),
    radius(radius),
    gravity(-9.81),
    xVelocity(1),
    yVelocity(1)
{

}

Ball::Ball(Coordinate coordinate,
           unsigned int radius,
           double gravity,
           double xVelocity,
           double yVelocity) :
    coordinate(coordinate),
    radius(radius),
    gravity(gravity),
    xVelocity(xVelocity),
    yVelocity(yVelocity)
{

}


bool Ball::verticalCollision() {
    return coordinate.getYCoordinate() >
        (signed int) (coordinate.getFrameHeight() - (signed int) radius)
        || coordinate.getYCoordinate() < (signed int) radius;
}

bool Ball::hitsGround() {
//    qDebug() << coordinate.getYCoordinate();
    return coordinate.getYCoordinate() < (signed int) radius;
}

bool Ball::horizontalCollision() {
return coordinate.getQtRenderingXCoordinate() < radius
        || coordinate.getQtRenderingXCoordinate() > WINDOW_WIDTH - radius;
}

unsigned int Ball::getRadius() {
    return radius;
}

void Ball::move(int x, int y) {
    coordinate.changeInXCoordinate(x);
    coordinate.changeInYCoordinate(y);
}

void Ball::jump() {
    yVelocity += 10;
}

void Ball::setXVelocity(int vel) {
    xVelocity = vel;
}

void Ball::setYVelocity(int vel) {
    yVelocity = vel;
}

void Ball::render(QPainter &painter)
{
    coordinate.changeInXCoordinate(xVelocity);
    coordinate.changeInYCoordinate(yVelocity);


    if (hitsGround()) {
        coordinate.setYCoordinateToZero(this->getRadius());
        // velocity decreases after hitting the ground
        yVelocity = 0;
    }
    else {
        yVelocity += gravity / 32.0;
    }

    if (horizontalCollision()) {
        xVelocity = 0;
    }


    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( Qt::yellow ) );
    painter.drawEllipse(coordinate.getQtRenderingXCoordinate() - int(radius),
        coordinate.getQtRenderingYCoordinate() - int(radius),
        radius * 2,
        radius * 2);

    xVelocity = 0;

}

