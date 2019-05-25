#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>
#include "renderer.h"
#include "observer.h"

#define SCORE_MOTION 0.1
#define SCORE_POWERUP 100
#define SCORE_OBSTACLE 1000

class ScoreObserver : public Observer {
public:
    ScoreObserver();
    virtual ~ScoreObserver();

    virtual void update(int val);
    void render(Renderer &renderer);

private:
    unsigned int hiscore;
    unsigned int currScore;
    QPixmap digits[10];
};

#endif // SCORE_H
