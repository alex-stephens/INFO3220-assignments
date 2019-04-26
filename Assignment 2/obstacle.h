#pragma once

#include <QPainter>
#include <iostream>

#include "coordinate.h"
#include "config.h"

class Obstacle
{
public:
    Obstacle();
    Obstacle(Coordinate coordinate, int height, int width, int repeat_span, int speed);

    // getters
    Coordinate getCoordinate() { return coordinate; }
    int getHeight() { return height; }
    int getWidth() { return width; }

    void render(QPainter &painter, bool paused);


private:
    Coordinate coordinate; // coordinate for the top left of the obstacle
    int height;
    int width;
    int repeat_span; // how long before the object repeats itself
    int speed = 0;
};

