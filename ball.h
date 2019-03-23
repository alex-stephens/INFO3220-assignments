#ifndef BALL_H
#define BALL_H

#include "params.h"
#include "coordinate.h"

#include <QPainter>
#include <QKeyEvent>

class Ball
{

public:
    Ball(Coordinate coordinate);
    Ball(Coordinate coordinate,
        unsigned int radius);
    Ball(Coordinate coordinate,
        unsigned int radius,
        double gravity,
        double xVelocity,
        double yVelocity);

    ~Ball() {
    }

    void render(QPainter &painter);
    void move(int x, int y);
    void jump();
    bool verticalCollision();
    bool horizontalCollision();
    bool hitsGround();
    unsigned int getRadius();

    void setXVelocity(int vel);
    void setYVelocity(int vel);

private:
    Ball();

    Coordinate coordinate;
    unsigned int radius;
    double gravity;
    double xVelocity;
    double yVelocity;
};

#endif // BALL_H
