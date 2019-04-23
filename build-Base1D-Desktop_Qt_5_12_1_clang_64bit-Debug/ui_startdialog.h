/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QPushButton *start;
    QLabel *label;
    QRadioButton *bg1_radio;
    QRadioButton *bg2_radio;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *bg1;
    QLabel *bg2;
    QLabel *label_5;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName(QString::fromUtf8("StartDialog"));
        StartDialog->resize(530, 408);
        start = new QPushButton(StartDialog);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(140, 340, 251, 32));
        label = new QLabel(StartDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 10, 131, 51));
        bg1_radio = new QRadioButton(StartDialog);
        bg1_radio->setObjectName(QString::fromUtf8("bg1_radio"));
        bg1_radio->setGeometry(QRect(180, 250, 21, 20));
        bg1_radio->setChecked(true);
        bg2_radio = new QRadioButton(StartDialog);
        bg2_radio->setObjectName(QString::fromUtf8("bg2_radio"));
        bg2_radio->setGeometry(QRect(340, 250, 21, 20));
        label_2 = new QLabel(StartDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 130, 141, 20));
        label_3 = new QLabel(StartDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 50, 81, 31));
        label_4 = new QLabel(StartDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 70, 111, 41));
        bg1 = new QLabel(StartDialog);
        bg1->setObjectName(QString::fromUtf8("bg1"));
        bg1->setGeometry(QRect(130, 160, 121, 81));
        bg2 = new QLabel(StartDialog);
        bg2->setObjectName(QString::fromUtf8("bg2"));
        bg2->setGeometry(QRect(290, 160, 121, 81));
        label_5 = new QLabel(StartDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 100, 111, 31));

        retranslateUi(StartDialog);

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QApplication::translate("StartDialog", "Dialog", nullptr));
        start->setText(QApplication::translate("StartDialog", "Start", nullptr));
        label->setText(QApplication::translate("StartDialog", "RUNNING STICKMAN", nullptr));
        bg1_radio->setText(QString());
        bg2_radio->setText(QString());
        label_2->setText(QApplication::translate("StartDialog", "Choose a Background", nullptr));
        label_3->setText(QApplication::translate("StartDialog", "Instructions:", nullptr));
        label_4->setText(QApplication::translate("StartDialog", "Pause: Press 'P'", nullptr));
        bg1->setText(QString());
        bg2->setText(QString());
        label_5->setText(QApplication::translate("StartDialog", "Quit: Press 'Q'", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
