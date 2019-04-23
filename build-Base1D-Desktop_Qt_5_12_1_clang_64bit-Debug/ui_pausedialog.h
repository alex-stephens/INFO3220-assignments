/********************************************************************************
** Form generated from reading UI file 'pausedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEDIALOG_H
#define UI_PAUSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_PauseDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QGroupBox *stickman_size;
    QRadioButton *tiny_radio;
    QRadioButton *normal_radio;
    QRadioButton *large_radio;
    QRadioButton *giant_radio;
    QGroupBox *stickman_position;
    QSlider *position_slider;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QDialog *PauseDialog)
    {
        if (PauseDialog->objectName().isEmpty())
            PauseDialog->setObjectName(QString::fromUtf8("PauseDialog"));
        PauseDialog->resize(518, 386);
        buttonBox = new QDialogButtonBox(PauseDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 300, 371, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);
        label_2 = new QLabel(PauseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 30, 51, 16));
        stickman_size = new QGroupBox(PauseDialog);
        stickman_size->setObjectName(QString::fromUtf8("stickman_size"));
        stickman_size->setGeometry(QRect(50, 120, 431, 61));
        tiny_radio = new QRadioButton(stickman_size);
        tiny_radio->setObjectName(QString::fromUtf8("tiny_radio"));
        tiny_radio->setGeometry(QRect(20, 30, 51, 20));
        normal_radio = new QRadioButton(stickman_size);
        normal_radio->setObjectName(QString::fromUtf8("normal_radio"));
        normal_radio->setGeometry(QRect(130, 30, 71, 20));
        normal_radio->setCheckable(true);
        normal_radio->setChecked(false);
        large_radio = new QRadioButton(stickman_size);
        large_radio->setObjectName(QString::fromUtf8("large_radio"));
        large_radio->setEnabled(true);
        large_radio->setGeometry(QRect(240, 30, 61, 20));
        large_radio->setChecked(false);
        giant_radio = new QRadioButton(stickman_size);
        giant_radio->setObjectName(QString::fromUtf8("giant_radio"));
        giant_radio->setGeometry(QRect(340, 30, 61, 20));
        stickman_position = new QGroupBox(PauseDialog);
        stickman_position->setObjectName(QString::fromUtf8("stickman_position"));
        stickman_position->setGeometry(QRect(50, 210, 431, 61));
        position_slider = new QSlider(stickman_position);
        position_slider->setObjectName(QString::fromUtf8("position_slider"));
        position_slider->setGeometry(QRect(50, 30, 321, 22));
        position_slider->setOrientation(Qt::Horizontal);
        label = new QLabel(stickman_position);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 21, 20));
        label_3 = new QLabel(stickman_position);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 30, 31, 21));

        retranslateUi(PauseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PauseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PauseDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PauseDialog);
    } // setupUi

    void retranslateUi(QDialog *PauseDialog)
    {
        PauseDialog->setWindowTitle(QApplication::translate("PauseDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("PauseDialog", "PAUSED", nullptr));
        stickman_size->setTitle(QApplication::translate("PauseDialog", "Stickman Size", nullptr));
        tiny_radio->setText(QApplication::translate("PauseDialog", "Tiny", nullptr));
        normal_radio->setText(QApplication::translate("PauseDialog", "Normal", nullptr));
        large_radio->setText(QApplication::translate("PauseDialog", "Large", nullptr));
        giant_radio->setText(QApplication::translate("PauseDialog", "Giant", nullptr));
        stickman_position->setTitle(QApplication::translate("PauseDialog", "Stickman Position", nullptr));
        label->setText(QApplication::translate("PauseDialog", "0", nullptr));
        label_3->setText(QApplication::translate("PauseDialog", "1280", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PauseDialog: public Ui_PauseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEDIALOG_H
