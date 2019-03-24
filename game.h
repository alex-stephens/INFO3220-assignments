#ifndef DIALOG_H
#define DIALOG_H

#include "ball.h"
#include "background.h"
#include "params.h"
#include "sprite.h"
#include "config.h"

#include <QDialog>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    Game(Background background, Sprite sprite);
    explicit Game(Config config);

    void keyPressEvent(QKeyEvent *event);
    void updateBackground(int shift);
    void setBackground(QString path, int offset);
    void drawSprite(QString path);

    ~Game();

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
//    Ball ball;
    Background background;
    Sprite sprite;
    int backgroundOffset = 0;
    QMovie *movie;
//    Config config;

    bool paused = false;
};


#endif // DIALOG_H