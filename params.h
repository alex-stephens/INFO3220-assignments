#ifndef PARAMS_H
#define PARAMS_H

#include <map>
#include <string>
#include <QString>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

#define BACKGROUND_SPEED 3

#define SIZE_TINY 30
#define SIZE_NORMAL 100
#define SIZE_LARGE 150
#define SIZE_GIANT 300

static std::map<QString, int> SIZE = {
    { "tiny", 30 },
    { "normal", 100 },
    { "large", 150 },
    { "giant", 300 }
};


#endif // PARAMS_H
