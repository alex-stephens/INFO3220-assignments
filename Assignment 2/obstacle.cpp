#include "obstacle.h"

Obstacle::Obstacle(Coordinate coordinate, int height, int width, int repeat_span, int speed)
    : coordinate(coordinate),
      height(height),
      width(width),
      repeat_span(repeat_span),
      speed(speed) { }

void Obstacle::render(QPainter &painter, bool paused) {
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    QBrush brush(Qt::yellow);
    painter.setPen (pen);
    painter.setBrush(brush);

    painter.drawRect(coordinate.getXCoordinate(), coordinate.getYCoordinate(), height, width);

    //If it isn't in pause, then adjust the position of all the components.
    if (!paused) {
        coordinate.changeInXCoordinate(-Config::config()->getStickman()->getXVelocity());

        // if it's off the screen, move it
        if (coordinate.getXCoordinate() < -width) {
            coordinate.changeInXCoordinate(repeat_span);
        }
    }
}
