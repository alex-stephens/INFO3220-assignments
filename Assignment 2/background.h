#pragma once

#include <QList>
#include <QPixmap>
#include <QPainter>
#include <QDialog>
#include <QMediaPlayer>

#include "coordinate.h"
#include "config.h"

class Background {

public:

    Background(Coordinate main_coordinate);
    ~Background() = default;

    //Render the background depending on if it is in a paused state or not
    void render(QPainter &painter, bool paused);

    //Getter functions
    Coordinate getCoordinate() { return main_coordinate; }
    QPixmap getFirst() { return first; }
    QPixmap getSecond() { return second; }
    QPixmap getThird() { return third; }
    int getVelocity() { return velocity; }

    //Setter functions
    void setVelocity(int new_velocity) { velocity = new_velocity; }

private:
    Coordinate main_coordinate;

    Coordinate first_coordinate;
    Coordinate second_coordinate;
    Coordinate third_coordinate;

    QPixmap first;
    QPixmap second;
    QPixmap third;

    int velocity = 0;
};



