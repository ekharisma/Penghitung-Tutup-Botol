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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QLabel *label;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *minRadEdit;
    QLabel *label_3;
    QLineEdit *MaxRadEdit;
    QLabel *label_2;
    QLineEdit *MeanEdit;
    QLabel *label_5;
    QLineEdit *thresEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *warna1Btn;
    QPushButton *bedaWarnaBtn;
    QLabel *label_8;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *redLabel;
    QLabel *label_13;
    QLabel *blueLabel;
    QLabel *label_15;
    QLabel *whiteLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_16;
    QLineEdit *maxBlue;
    QLineEdit *minWhite;
    QLineEdit *minBlue;
    QLineEdit *maxRed;
    QLineEdit *minRed;
    QLineEdit *maxWhite;
    QPushButton *setVarBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 484);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        videoPath = new QLineEdit(centralwidget);
        videoPath->setObjectName(QString::fromUtf8("videoPath"));
        videoPath->setGeometry(QRect(110, 410, 261, 26));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 400, 81, 41));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 10, 551, 381));
        graphicsView->setFrameShape(QFrame::VLine);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(600, 10, 160, 261));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        minRadEdit = new QLineEdit(verticalLayoutWidget);
        minRadEdit->setObjectName(QString::fromUtf8("minRadEdit"));

        verticalLayout_2->addWidget(minRadEdit);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        MaxRadEdit = new QLineEdit(verticalLayoutWidget);
        MaxRadEdit->setObjectName(QString::fromUtf8("MaxRadEdit"));

        verticalLayout_2->addWidget(MaxRadEdit);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        MeanEdit = new QLineEdit(verticalLayoutWidget);
        MeanEdit->setObjectName(QString::fromUtf8("MeanEdit"));

        verticalLayout_2->addWidget(MeanEdit);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        thresEdit = new QLineEdit(verticalLayoutWidget);
        thresEdit->setObjectName(QString::fromUtf8("thresEdit"));

        verticalLayout_2->addWidget(thresEdit);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(600, 340, 171, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        warna1Btn = new QPushButton(horizontalLayoutWidget);
        warna1Btn->setObjectName(QString::fromUtf8("warna1Btn"));

        horizontalLayout->addWidget(warna1Btn);

        bedaWarnaBtn = new QPushButton(horizontalLayoutWidget);
        bedaWarnaBtn->setObjectName(QString::fromUtf8("bedaWarnaBtn"));

        horizontalLayout->addWidget(bedaWarnaBtn);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(660, 310, 58, 18));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(790, 310, 161, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setPointSize(10);
        label_7->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_7);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        redLabel = new QLabel(formLayoutWidget);
        redLabel->setObjectName(QString::fromUtf8("redLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, redLabel);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        blueLabel = new QLabel(formLayoutWidget);
        blueLabel->setObjectName(QString::fromUtf8("blueLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, blueLabel);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_15);

        whiteLabel = new QLabel(formLayoutWidget);
        whiteLabel->setObjectName(QString::fromUtf8("whiteLabel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, whiteLabel);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(780, 9, 160, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 2, 0, 1, 2);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 0, 1, 2);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 4, 0, 1, 2);

        maxBlue = new QLineEdit(gridLayoutWidget);
        maxBlue->setObjectName(QString::fromUtf8("maxBlue"));

        gridLayout->addWidget(maxBlue, 3, 1, 1, 1);

        minWhite = new QLineEdit(gridLayoutWidget);
        minWhite->setObjectName(QString::fromUtf8("minWhite"));

        gridLayout->addWidget(minWhite, 5, 0, 1, 1);

        minBlue = new QLineEdit(gridLayoutWidget);
        minBlue->setObjectName(QString::fromUtf8("minBlue"));

        gridLayout->addWidget(minBlue, 3, 0, 1, 1);

        maxRed = new QLineEdit(gridLayoutWidget);
        maxRed->setObjectName(QString::fromUtf8("maxRed"));

        gridLayout->addWidget(maxRed, 1, 1, 1, 1);

        minRed = new QLineEdit(gridLayoutWidget);
        minRed->setObjectName(QString::fromUtf8("minRed"));

        gridLayout->addWidget(minRed, 1, 0, 1, 1);

        maxWhite = new QLineEdit(gridLayoutWidget);
        maxWhite->setObjectName(QString::fromUtf8("maxWhite"));

        gridLayout->addWidget(maxWhite, 5, 1, 1, 1);

        setVarBtn = new QPushButton(centralwidget);
        setVarBtn->setObjectName(QString::fromUtf8("setVarBtn"));
        setVarBtn->setGeometry(QRect(690, 280, 158, 26));
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
        label->setText(QCoreApplication::translate("MainWindow", "Video Path", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Min Radius", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Max Radius", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Gaussian Blur", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Threshold Center", nullptr));
        warna1Btn->setText(QCoreApplication::translate("MainWindow", "1 Warna", nullptr));
        bedaWarnaBtn->setText(QCoreApplication::translate("MainWindow", "Warna Beda", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Mode : ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Jumlah Botol", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Merah : ", nullptr));
        redLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Biru : ", nullptr));
        blueLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Putih : ", nullptr));
        whiteLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "White", nullptr));
        setVarBtn->setText(QCoreApplication::translate("MainWindow", "Set Variable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
