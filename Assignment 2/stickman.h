#pragma once

#include <iostream>
#include <string>
#include <QPixmap>

class Stickman {

public:

    Stickman(std::string size = "small",
            int position = 0,
            double starting_velocity = 0.0);

    ~Stickman();

    //Getter functions
    std::string getSize() { return size; }
    int getXPosition() { return position; }
    double getVelocity() { return xvelocity; }
    double getWidth() { return width; }
    double getHeight() { return height; }
    virtual QPixmap getPixmap(unsigned int frame);

    //Change and set functions
    void changeSize(std::string new_size) { size = new_size; }
    void changeXPosition(int new_position) { position = new_position; }
    void changeXVelocity(int new_velocity) { xvelocity = new_velocity; }
    virtual void setDimensions();
    virtual void updateStickman();


private:

    std::string size;
    int position;
    double xvelocity;
    int width;
    int height;

};

