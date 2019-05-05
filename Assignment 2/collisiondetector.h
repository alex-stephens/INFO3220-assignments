#pragma once

#include <vector>
#include <algorithm>

#include "obstacle.h"
#include "config.h"


class CollisionDetector
{
public:
    CollisionDetector(std::vector<Obstacle>& obstacles);

    void checkCollisions();
    void applyCollisions();
    void checkVerticalCollisions();

    // getters and setters
    std::vector<Obstacle> getObstacles(void) { return obstacles; }
    void setObstacles(std::vector<Obstacle>& new_obstacles) { obstacles = new_obstacles; }

private:
    std::vector<Obstacle>& obstacles;
    bool horizontal_collision = false;
    bool upward_collision = false;
    bool downward_collision = false;
    int collisionX = 0;
    int collisionY = 0;

    QSoundEffect effect;

    // buffer - can't have two collisions within 3 frames
    int prev_collision = 0;

};
