#include "obstacle.h"

Obstacle::Obstacle()
    :coordinate(0,0,1000,800),
      height(100),
      width(100),
      repeat_span(1000),
      speed(10),
      color("#ffff00") { }

Obstacle::Obstacle(Coordinate coordinate, int height, int width, int repeat_span, int speed, QString color)
    : coordinate(coordinate),
      height(height),
      width(width),
      repeat_span(repeat_span),
      speed(speed),
      color(color) { }

void Obstacle::render(QPainter &painter, bool paused) {
    QPen pen;
    QColor qcolor(color);
    pen.setWidth(3);
    pen.setColor(Qt::black);

    QBrush brush(qcolor);
    painter.setPen (pen);
    painter.setBrush(brush);

    painter.drawRect(coordinate.getQtRenderingXCoordinate(), coordinate.getQtRenderingYCoordinate(), width, height);

    //If it isn't in pause, then adjust the position of all the components.
    if (!paused) {
        coordinate.changeInXCoordinate(-Config::config()->getStickman()->getXVelocity());

        // if it's off the screen, move it
        if (coordinate.getXCoordinate() < -width) {
            coordinate.changeInXCoordinate(repeat_span);
        }
    }
}
