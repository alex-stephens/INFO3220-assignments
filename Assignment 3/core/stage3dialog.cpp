#include "stage3dialog.h"
#include <iostream>

Stage3Dialog::Stage3Dialog(Game &game, std::unique_ptr<FlyingStickman> stickman, std::unique_ptr<EntityFactory> factory, std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
    Stage2Dialog(game, std::move(stickman), std::move(factory), std::move(obstacleLayout)) {
}

void Stage3Dialog::update() {
    stickman->update(obstacles);
    background.setVelocity(stickman->getVelocity());
    updateObservers(stickman->getVelocity() * SCORE_MOTION);

    stickman->setVelocity(stickman->getVelocity() * 0.9); // motion smoothing -- don't drop to 0 immediately

    if (!stickman->isColliding()) {
        // Reduce distance to next obstacle

        changeDistanceToSpawn(-background.getVelocity());
        background.update();
        speedUp(counter);
        for (auto &o : obstacles) {
            o->setVelocity(background.getVelocity());
        }
    }

    else {
        lives.decrement();
    }

    spawnObstacles(counter);
    spawnPowerUps(counter);

    bool col = false;
    for (auto &o : obstacles) {
        o->collisionLogic(*stickman);
        if (stickman->isColliding()) {
            col = true;
        }
    }

    // restart the level if colliding sidelong with an obstacle
    if (col) {
        nextObstacle = 0;
        distanceToSpawn = 1000;
        for (auto it = obstacles.begin(); it != obstacles.end(); ) {
            obstacles.erase(it);
        }
    }

}

void Stage3Dialog::spawnPowerUps(unsigned int counter) {
    // Check if it's time to spawn a powerup
//    if (counter % 1000 != 0) return;
    if (rand() % 200 != 0) return; // one in 1000 chance to spawn a powerup

    std::cout << "SPAWNING POWERUP" << std::endl;

//    auto pwr = new PowerUp(Coordinate(100,100,600), 10);
    std::unique_ptr<PowerUp> powerUp( new PowerUp(Coordinate(1000,150 + rand() % 500,450), 0));
    powerUp->randomiseSize();

    // Check for collisions between next obstacle and current obstacles
    bool isOverlapping = false;
    for (auto &o : obstacles) {
        if (Collision::overlaps(*powerUp, *o)) {
            isOverlapping = true;
            break;
        }
    }


//     Only spawn the obstacle if it isn't colliding with anything
    if (!isOverlapping) {
        powerUp->setVelocity(background.getVelocity());
        addObstacle(std::move(powerUp));
    }

}


void Stage3Dialog::render(Renderer& renderer) {
    Dialog::render(renderer); // Call the base method before doing our own.
    lives.render(renderer);
}


