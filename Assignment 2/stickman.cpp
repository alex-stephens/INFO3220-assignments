#include "stickman.h"

Stickman::~Stickman() {
    std::cout << "Deleted Stickman" << std::endl;
}

//Set the scaled dimensions of the stickman, depending on the given size
void Stickman::setDimensions() {

    if (size == "tiny") {
        width = getPixmap(1).width() * 0.6;
        height = getPixmap(1).height() * 0.6;
    }

    else if (size == "normal") {
        width = getPixmap(1).width();
        height = getPixmap(1).height();
    }

    else if (size == "large") {
        width = getPixmap(1).width() * 1.2;
        height = getPixmap(1).height() * 1.2;
    }

    else if (size == "giant") {
        width = getPixmap(1).width() * 1.5;
        height = getPixmap(1).height() * 1.5;
    }


}

Stickman::Stickman(std::string size,
                   int xposition,
                   double xvelocity)
    : size(size),
      xposition(xposition),
      xvelocity(xvelocity) {

    setDimensions();

}

void Stickman::resizeStickman() {
    setDimensions();
}

//Get the respective pixmap for the given frame
QPixmap Stickman::getPixmap(unsigned int frame) {
    QString frame_path = ":img/stickman/frame" + QString::number(frame) + ".png";
    QPixmap pix(frame_path);
    return pix;
}

// perform dynamics update: does nothing in the base class
void Stickman::update() {
    return;
}
