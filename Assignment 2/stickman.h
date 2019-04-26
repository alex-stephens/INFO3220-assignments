#pragma once

#include <iostream>
#include <string>
#include <QPixmap>


class Stickman {

public:

    Stickman(std::string size = "small",
            int xposition = 0,
            double starting_velocity = 0.0);

    virtual ~Stickman();

    //Getter functions
    virtual std::string getSize() { return size; }
    virtual int getXPosition() { return xposition; }
    virtual double getXVelocity() { return xvelocity; }
    virtual double getWidth() { return width; }
    virtual double getHeight() { return height; }
    virtual QPixmap getPixmap(unsigned int frame);

    //Change and set functions
    virtual void setSize(std::string new_size) { size = new_size; }
    virtual void setXPosition(int new_position) { xposition = new_position; }
    virtual void setXVelocity(int new_velocity) { xvelocity = new_velocity; }
    virtual void setDimensions();
    virtual void resizeStickman();

    // addition for stage 2 extensibility, does nothing here in the base class
    virtual void update();

private:

    std::string size;
    int xposition;
    double xvelocity;
    int width;
    int height;

};

