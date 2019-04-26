#include "stage2stickman.h"

//Stage2Stickman::Stage2Stickman(std::string size,
//                   int xposition,
//                   double xvelocity)
//{
//    changeSize(size);
//    changeXPosition(xposition);
//    changeXVelocity(xvelocity);
//    setDimensions();
//}


void Stage2Stickman::update() {

    yposition += yvelocity;
    yvelocity -= 2; // gravity

    // hitting the ground
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
        ++jumpctr;
    }
}
