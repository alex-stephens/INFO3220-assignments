#ifndef OBSERVER_H
#define OBSERVER_H

#include "renderer.h"

class Observer
{
public:
    Observer();
    ~Observer();

    void render(Renderer &renderer);
    void update(int val);
};

#endif // OBSERVER_H
