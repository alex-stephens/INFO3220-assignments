#pragma once

#include <QTimer>
#include <QDialog>
#include <QAbstractButton>
#include <iostream>


#include "config.h"

namespace Ui {
class PauseDialog;
}

class PauseDialog : public QDialog {
    Q_OBJECT

public:
    explicit PauseDialog(bool *paused, QWidget *parent = 0);
    ~PauseDialog();

    virtual void setUpUI();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_position_slider_actionTriggered(int action);
    void on_tiny_radio_clicked();
    void on_normal_radio_clicked();
    void on_large_radio_clicked();
    void on_giant_radio_clicked();

private:
    Ui::PauseDialog *ui;
    bool *paused;
};

