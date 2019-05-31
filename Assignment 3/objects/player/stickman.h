#ifndef STICKMAN_H
#define STICKMAN_H

#include "gameobject.h"
#include "coordinate.h"
#include "renderer.h"
#include "scoreobserver.h"
#include <string>
#include <QPainter>
#include <QKeyEvent>
#include <vector>
#include <memory>


class Entity;
class Stickman : public GameObject {
public:
    Stickman() = default;
    virtual ~Stickman();

    void setCoordinate(Coordinate coordinate);

    void setSize(std::string size);
    std::string getSize();

    virtual void setSprite(std::string path);

    Coordinate &getCoordinate();

    virtual void render(Renderer &renderer, unsigned int time);

    virtual void handleInput(QKeyEvent &event);
    virtual void update(std::vector<std::unique_ptr<Entity>> &obstacles);

    bool isColliding();
    int width();
    int height();

    int getVelocity() { return velocity; }
    void setVelocity(int val) { velocity = val; }

    void attach(Observer* obs);
    void updateObservers(int val);

protected:
    std::vector<Observer*> observers;
    ScoreObserver observer;

    bool colliding;
    std::string size;
    QPixmap sprite;
    Coordinate coordinate;


private:
    int velocity = 5;
};

#endif // STICKMAN_H
