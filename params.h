#ifndef PARAMS_H
#define PARAMS_H

#include <map>
#include <string>
#include <QString>

// window size and background is required as 800 x 400
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

#define RESOURCES_PATH "/Users/alex/Dropbox/University/2019 Semester 1/INFO3220/INFO3220-assignment-1/resources/"

// map of size strings to pixel values
static std::map<QString, int> SIZE = {
    { "tiny", 30 },
    { "normal", 50 },
    { "large", 70 },
    { "giant", 100 }
};


#endif // PARAMS_H
