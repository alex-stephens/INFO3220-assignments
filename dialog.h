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

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void keyPressEvent(QKeyEvent *event);
    void updateBackground(int shift);
    void setBackground(QString path, int offset);
    void drawSprite(QString path);

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Ball ball;
    Background background;
    Sprite sprite;
    int backgroundOffset = 0;
    QMovie *movie;
};


#endif // DIALOG_H
