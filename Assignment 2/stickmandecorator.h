#pragma once

#include "stage2stickman.h"

class StickmanDecorator : public Stage2Stickman
{
    Stage2Stickman* stickman;

public:
    StickmanDecorator(Stage2Stickman* stickman) : stickman(stickman) {
        std::cout << "Constructed---StickmanDecorator" << std::endl;
        std::cout << "X position: " << this->stickman->getXPosition() << std::endl;
    }

    // getters
    std::string getSize() override { return stickman->getSize(); }
    int getXPosition() override { return stickman->getXPosition(); }
    double getXVelocity() override { return stickman->getXVelocity(); }
    double getWidth() override { return stickman->getWidth(); }
    double getHeight() override { return stickman->getHeight(); }
    QPixmap getPixmap(unsigned int frame) override { return stickman->getPixmap(frame); }

    int getYPosition() override { return stickman->getYPosition(); }
    double getYVelocity() override { return stickman->getYVelocity(); }

    //Change and set functions
    void changeSize(std::string new_size) override { stickman->changeSize(new_size); }
    void setXPosition(int new_position) override { stickman->setXPosition(new_position); }
    void setXVelocity(int new_velocity) override { stickman->setXVelocity(new_velocity); }
    virtual void setDimensions() override { stickman->setDimensions(); }
    virtual void resizeStickman() override { stickman->resizeStickman(); }

    void setYPosition(int new_position) override { stickman->setYPosition(new_position); }
    void setYVelocity(int new_velocity) override { stickman->setYVelocity(new_velocity); }
    void setPosition(int x, int y) override { stickman->setPosition(x,y); }



    virtual void update() override {
        stickman->update(); // update by delegation
    }

    virtual void jump() override {
        stickman->jump();
    }
};

