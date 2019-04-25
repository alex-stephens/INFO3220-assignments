#include "stage2stickman.h"

void Stage2Stickman::update() {
    yvelocity -= 2;
    yposition += yvelocity;

    if (yposition <= 0) {
        yposition = 0;
        yvelocity = 0;
        jumpctr = 0;
    }
}

void Stage2Stickman::jump() {
    if (jumpctr < 2) {
        yvelocity = 30;
        std::cout << "stickman jumped" << std::endl;
        jumpctr++;
    }
}
