#ifndef DIALOG_H
#define DIALOG_H

#include "ball.h"
#include <QDialog>
#include <QTimer>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600

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

public slots:
    void nextFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Ball m_ball;
    unsigned int m_counter;
};


#endif // DIALOG_H
