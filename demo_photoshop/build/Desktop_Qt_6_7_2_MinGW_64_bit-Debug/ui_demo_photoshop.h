/********************************************************************************
** Form generated from reading UI file 'demo_photoshop.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_PHOTOSHOP_H
#define UI_DEMO_PHOTOSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demo_photoshop
{
public:
    QWidget *centralwidget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCalendarWidget *calendarWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *demo_photoshop)
    {
        if (demo_photoshop->objectName().isEmpty())
            demo_photoshop->setObjectName("demo_photoshop");
        demo_photoshop->resize(1238, 700);
        demo_photoshop->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        demo_photoshop->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 38, 98);\n"
""));
        demo_photoshop->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonFollowStyle);
        demo_photoshop->setAnimated(true);
        demo_photoshop->setTabShape(QTabWidget::TabShape::Triangular);
        centralwidget = new QWidget(demo_photoshop);
        centralwidget->setObjectName("centralwidget");
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");
        toolButton->setEnabled(true);
        toolButton->setGeometry(QRect(1140, 620, 91, 31));
        toolButton->setAutoFillBackground(false);
        toolButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton->setCheckable(false);
        toolButton->setChecked(false);
        toolButton->setAutoExclusive(false);
        toolButton->setAutoRepeatInterval(300);
        toolButton->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonFollowStyle);
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setEnabled(true);
        toolButton_2->setGeometry(QRect(1030, 620, 91, 31));
        toolButton_2->setAutoFillBackground(false);
        toolButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_2->setCheckable(false);
        toolButton_2->setChecked(false);
        toolButton_2->setAutoExclusive(false);
        toolButton_2->setAutoRepeatInterval(300);
        toolButton_2->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonFollowStyle);
        toolButton_2->setAutoRaise(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 40, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);\n"
"background-color: rgb(84, 80, 129);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(320, 40, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 80, 129);"));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(50, 100, 93, 26));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(50, 140, 111, 26));
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(50, 180, 93, 26));
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(50, 220, 93, 26));
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(190, 100, 93, 26));
        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(190, 140, 93, 26));
        checkBox_7 = new QCheckBox(centralwidget);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(190, 180, 241, 26));
        checkBox_8 = new QCheckBox(centralwidget);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setGeometry(QRect(190, 220, 93, 26));
        checkBox_9 = new QCheckBox(centralwidget);
        checkBox_9->setObjectName("checkBox_9");
        checkBox_9->setGeometry(QRect(470, 100, 93, 26));
        checkBox_10 = new QCheckBox(centralwidget);
        checkBox_10->setObjectName("checkBox_10");
        checkBox_10->setGeometry(QRect(470, 140, 121, 26));
        checkBox_11 = new QCheckBox(centralwidget);
        checkBox_11->setObjectName("checkBox_11");
        checkBox_11->setGeometry(QRect(470, 180, 93, 26));
        checkBox_12 = new QCheckBox(centralwidget);
        checkBox_12->setObjectName("checkBox_12");
        checkBox_12->setGeometry(QRect(470, 220, 93, 26));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(70, 340, 344, 195));
        demo_photoshop->setCentralWidget(centralwidget);
        menubar = new QMenuBar(demo_photoshop);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1238, 25));
        demo_photoshop->setMenuBar(menubar);
        statusbar = new QStatusBar(demo_photoshop);
        statusbar->setObjectName("statusbar");
        demo_photoshop->setStatusBar(statusbar);

        retranslateUi(demo_photoshop);

        QMetaObject::connectSlotsByName(demo_photoshop);
    } // setupUi

    void retranslateUi(QMainWindow *demo_photoshop)
    {
        demo_photoshop->setWindowTitle(QCoreApplication::translate("demo_photoshop", "demo_photoshop", nullptr));
        toolButton->setText(QCoreApplication::translate("demo_photoshop", "Apply", nullptr));
        toolButton_2->setText(QCoreApplication::translate("demo_photoshop", "Cancel", nullptr));
        pushButton->setText(QCoreApplication::translate("demo_photoshop", "Undo", nullptr));
        pushButton_2->setText(QCoreApplication::translate("demo_photoshop", "Redo", nullptr));
        checkBox->setText(QCoreApplication::translate("demo_photoshop", "Grayscale", nullptr));
        checkBox_2->setText(QCoreApplication::translate("demo_photoshop", "Black_White", nullptr));
        checkBox_3->setText(QCoreApplication::translate("demo_photoshop", "Invert", nullptr));
        checkBox_4->setText(QCoreApplication::translate("demo_photoshop", "Merge", nullptr));
        checkBox_5->setText(QCoreApplication::translate("demo_photoshop", "Flip", nullptr));
        checkBox_6->setText(QCoreApplication::translate("demo_photoshop", "Rotate", nullptr));
        checkBox_7->setText(QCoreApplication::translate("demo_photoshop", "Darken and Lighten Image", nullptr));
        checkBox_8->setText(QCoreApplication::translate("demo_photoshop", "Crop", nullptr));
        checkBox_9->setText(QCoreApplication::translate("demo_photoshop", "Frame", nullptr));
        checkBox_10->setText(QCoreApplication::translate("demo_photoshop", "Detect Edges", nullptr));
        checkBox_11->setText(QCoreApplication::translate("demo_photoshop", "Resize", nullptr));
        checkBox_12->setText(QCoreApplication::translate("demo_photoshop", "Blur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class demo_photoshop: public Ui_demo_photoshop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_PHOTOSHOP_H
