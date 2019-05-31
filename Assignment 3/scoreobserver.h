#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <stack>
#include <QPainter>
#include <QPixmap>
#include "renderer.h"
#include "observer.h"

#define SCORE_MOTION 0.1
#define SCORE_POWERUP 1000
#define SCORE_OBSTACLE 5000

// I decided it was fair game to (somewhat) re-implement Score as an Observer,
// since scoring wasn't meant to be part of Stage 2.

class ScoreObserver : public Observer {
public:
    ScoreObserver();
    ~ScoreObserver() {}

    void update(int val);
    void render(Renderer &renderer);

private:
    unsigned int hiscore;
    unsigned int currScore;
    QPixmap digits[10];
};

#endif // SCORE_H
