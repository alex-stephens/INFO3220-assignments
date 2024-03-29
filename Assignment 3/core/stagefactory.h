#ifndef STAGEFACTORY_H
#define STAGEFACTORY_H

#include <QString>
#include <memory>
#include <iostream>
#include "entity.h"
#include "gamestage.h"
#include "game.h"
#include "entityfactory.h"
#include "dialog.h"
#include "collisiontest.h"
#include "jumptest.h"
#include "flyingobstacletest.h"
#include "swaprendererstage.h"
#include "testingdialog.h"
#include "stage2dialog.h"
#include "stage3dialog.h"
#include "dialog.h"
#include "moon.h"
#include "background.h"
#include "flyingstickman.h"


class StageFactory {
public:
    // This wouldn't be necessary if JSON was used instead of a custom config file format, but rewriting it wasn't an option
    struct Config {
        int stage;
        bool testMode;
        std::string background;
        Coordinate coord;
        int velocity;
        std::string size;

        Game *game;
        std::vector<std::pair<std::unique_ptr<Entity>, int>> *obstacles;

        int numLives;
    };

    /**
     * @brief StageFactory
     * @param config The initial configuration the constructed stage will be based on
     */
    StageFactory(Config config);

    std::unique_ptr<GameStage> createStage();

private:
    /**
     * @brief genericDialogInitializer
     * @param dialog A helper method for performing tasks common among all stages to avoid code duplication (e.g. background setup)
     */
    void genericDialogInitializer(Dialog &dialog);

    Config config;
};

#endif // STAGEFACTORY_H
