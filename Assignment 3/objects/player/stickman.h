#ifndef STICKMAN_H
#define STICKMAN_H

#include "gameobject.h"
#include "coordinate.h"
#include "renderer.h"
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

    void render(Renderer &renderer, unsigned int time);

    virtual void handleInput(QKeyEvent &event);
    virtual void update(std::vector<std::unique_ptr<Entity>> &obstacles);

    virtual void notify(int val);

    bool isColliding();
    int width();
    int height();

    int getVelocity() { return velocity; }
    void setVelocity(int val) { velocity = val; }

protected:
    bool colliding;
    std::string size;
    QPixmap sprite;

private:
    Coordinate coordinate;
    int velocity = 5;
};

#endif // STICKMAN_H
