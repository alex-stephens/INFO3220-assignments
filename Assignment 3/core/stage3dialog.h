#ifndef STAGE3DIALOG_H
#define STAGE3DIALOG_H

#include "stage2dialog.h"
#include "flyingstickman.h"
#include "lives.h"

class Stage3Dialog : public Stage2Dialog
{
public:

    Stage3Dialog(Game &game, std::unique_ptr<FlyingStickman> stickman, std::unique_ptr<EntityFactory> factory, std::vector<std::pair<std::unique_ptr<Entity>, int>> obstacleLayout);

    virtual void update() override;

    virtual void render(Renderer& renderer);

    virtual Lives& getLives() { return lives; }

private:
    Lives lives;

};

#endif // STAGE3DIALOG_H
