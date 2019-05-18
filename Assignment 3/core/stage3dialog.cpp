#include "stage3dialog.h"

Stage3Dialog::Stage3Dialog(Game &game, std::unique_ptr<Stickman> stickman, std::unique_ptr<EntityFactory> factory, std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
    Stage2Dialog(game, std::move(stickman), std::move(factory), std::move(obstacleLayout)) {
}

void Stage3Dialog::update() {
    stickman->update(obstacles);
    if (!stickman->isColliding()) {
        // Reduce distance to next obstacle
        changeDistanceToSpawn(-background.getVelocity());
//        distanceToSpawn -= background.getVelocity();
        background.update();
        speedUp(counter);
        score.increment();
    }
    spawnObstacles(counter);

    for (auto &c : clouds) {
        c->collisionLogic(*stickman);
    }

    for (auto &o : obstacles) {
        o->collisionLogic(*stickman);
    }
}
