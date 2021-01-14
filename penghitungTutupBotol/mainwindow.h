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
using namespace cv;
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
    void on_setVarBtn_clicked();

    void on_warna1Btn_clicked();

    void on_bedaWarnaBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsPixmapItem pixmap;
    cv::VideoCapture video;
    bool isCamera;
    int threshold = 100;
    int minRad = 1;
    int maxRad = 30;
    int blur_coef = 5;
    int redMin = 0;
    int redMax = 179;
    int greenMin = 0;
    int greenMax = 131;
    int blueMin = 94;
    int blueMax = 126;
    int whiteMin = 0;
    int whiteMax = 131;
    cv::Mat frame, gray;
};
#endif // MAINWINDOW_H
