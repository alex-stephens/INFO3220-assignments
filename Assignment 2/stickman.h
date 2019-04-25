#pragma once

#include <iostream>
#include <string>
#include <QPixmap>

class Stickman {

public:

    Stickman(std::string size = "small",
            int xposition = 0,
            double starting_velocity = 0.0);

    ~Stickman();

    //Getter functions
    std::string getSize() { return size; }
    int getXPosition() { return xposition; }
    double getXVelocity() { return xvelocity; }
    double getWidth() { return width; }
    double getHeight() { return height; }
    virtual QPixmap getPixmap(unsigned int frame);

    //Change and set functions
    void changeSize(std::string new_size) { size = new_size; }
    void changeXPosition(int new_position) { xposition = new_position; }
    void changeXVelocity(int new_velocity) { xvelocity = new_velocity; }
    virtual void setDimensions();
    virtual void resizeStickman();

    // addition for stage 2 extensibility, does nothing here in the base class
    virtual void update(void);

private:

    std::string size;
    int xposition;
    double xvelocity;
    int width;
    int height;

};

