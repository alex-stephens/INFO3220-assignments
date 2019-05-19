#include "stage3dialog.h"

Stage3Dialog::Stage3Dialog(Game &game, std::unique_ptr<FlyingStickman> stickman, std::unique_ptr<EntityFactory> factory, std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout) :
    Stage2Dialog(game, std::move(stickman), std::move(factory), std::move(obstacleLayout)) {
}

void Stage3Dialog::update() {
    stickman->update(obstacles);
    background.setVelocity(stickman->getVelocity());
    stickman->setVelocity(stickman->getVelocity() * 0.95); // motion smoothing -- don't drop to 0 immediately

    if (!stickman->isColliding()) {
        // Reduce distance to next obstacle

        changeDistanceToSpawn(-background.getVelocity());
        background.update();
//        speedUp(counter);
//        score.increment();
        for (auto &o : obstacles) {
            o->setVelocity(background.getVelocity());
        }
    }
    spawnObstacles(counter);

    for (auto &c : clouds) {
        c->collisionLogic(*stickman);
    }

    for (auto &o : obstacles) {
        o->collisionLogic(*stickman);
    }

}
