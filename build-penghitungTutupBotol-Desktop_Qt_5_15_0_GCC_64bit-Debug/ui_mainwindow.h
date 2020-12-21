/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *videoPath;
    QPushButton *pushButton;
    QLabel *label;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *minRadeEdit;
    QLabel *label_3;
    QLineEdit *maxRadEdit;
    QLabel *label_4;
    QLineEdit *meanEdit;
    QLabel *label_5;
    QLineEdit *thresEdit;
    QPushButton *setVarBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 594);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        videoPath = new QLineEdit(centralwidget);
        videoPath->setObjectName(QString::fromUtf8("videoPath"));
        videoPath->setGeometry(QRect(100, 520, 571, 26));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(700, 520, 80, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 510, 81, 41));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 10, 741, 501));
        graphicsView->setFrameShape(QFrame::VLine);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(780, 10, 160, 291));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        minRadeEdit = new QLineEdit(verticalLayoutWidget);
        minRadeEdit->setObjectName(QString::fromUtf8("minRadeEdit"));

        verticalLayout_2->addWidget(minRadeEdit);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        maxRadEdit = new QLineEdit(verticalLayoutWidget);
        maxRadEdit->setObjectName(QString::fromUtf8("maxRadEdit"));

        verticalLayout_2->addWidget(maxRadEdit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        meanEdit = new QLineEdit(verticalLayoutWidget);
        meanEdit->setObjectName(QString::fromUtf8("meanEdit"));

        verticalLayout_2->addWidget(meanEdit);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        thresEdit = new QLineEdit(verticalLayoutWidget);
        thresEdit->setObjectName(QString::fromUtf8("thresEdit"));

        verticalLayout_2->addWidget(thresEdit);

        setVarBtn = new QPushButton(verticalLayoutWidget);
        setVarBtn->setObjectName(QString::fromUtf8("setVarBtn"));

        verticalLayout_2->addWidget(setVarBtn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Video Path", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Min Radius", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Max Radius", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Mean", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Threshold Center", nullptr));
        setVarBtn->setText(QCoreApplication::translate("MainWindow", "Set Variable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
