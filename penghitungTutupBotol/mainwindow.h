#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/videoio.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void cvt_params();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_clicked();


    void on_setVarBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsPixmapItem pixmap;
    cv::VideoCapture video;
    bool isCamera;
    int threshold = 200;
    int minRad = 1;
    int maxRad = 30;
    int blur_coef = 5;
};
#endif // MAINWINDOW_H
