#pragma once

#include <vector>
#include <algorithm>

#include "obstacle.h"
#include "config.h"


class CollisionDetector
{
public:
//    virtual ~CollisionDetector();
//    CollisionDetector();
    CollisionDetector(std::vector<Obstacle>& obstacles);

    void checkHorizontalCollisions();
    void checkVerticalCollisions();

    // getters and setters
    std::vector<Obstacle> getObstacles(void) { return obstacles; }
    void setObstacles(std::vector<Obstacle>& new_obstacles) { obstacles = new_obstacles; }



private:
    std::vector<Obstacle>& obstacles;
};
