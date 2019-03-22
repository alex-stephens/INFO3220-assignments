#ifndef DIALOG_H
#define DIALOG_H

#include "ball.h"
#include <QDialog>
#include <QTimer>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

#define BACKGROUND_SPEED 3

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
    int backgroundOffset = 0;
    QMovie *movie;
};


#endif // DIALOG_H
