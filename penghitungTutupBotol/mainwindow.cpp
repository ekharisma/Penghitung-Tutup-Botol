#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unistd.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addItem(&pixmap);
    ui->minRadEdit->setText(QString::number(minRad));
    ui->MaxRadEdit->setText(QString::number(maxRad));
    ui->thresEdit->setText(QString::number(threshold));
    ui->MeanEdit->setText(QString::number(blur_coef));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent* event){
    if(video.isOpened()){
        QMessageBox::warning(
                    this,
                    "Warning",
                    "Tutup Video Sebelum Menutup Aplikasi");
        event->ignore();
    }
    else {
        event->accept();
    }

}

void MainWindow::on_pushButton_clicked(){
    if (video.isOpened()){
        ui->pushButton->setText("Start");
        video.release();
        QMessageBox::information(
                    this,
                    "Kamera berhenti",
                    "Keluar dari window ini untuk memulai kamera kembali");
        return;
    }
    int cameraIndex = ui->videoPath->text().toInt(&isCamera);
    if (isCamera){
        if(!video.open(cameraIndex)){
            QMessageBox::critical(
                        this,
                        "Camera Error",
                        "Pastikan anda memasukan indeks kamera dengan benar");
            return;
        }
    }
    else {
        if(!video.open(ui->videoPath->text().trimmed().toStdString())){
            QMessageBox::critical(
                        this,
                        "Camera Error",
                        "Video format tidak didukung");
            return;
        }
    }
    ui->pushButton->setText("Stop");
    cv::Mat frame, gray;
    while (video.isOpened()) {
        video >> frame;
        if (! frame.empty()){
            unsigned int microsecond = 10000;
            usleep(0.5 * microsecond);//sleeps for 3 second
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::medianBlur(gray, gray, blur_coef);
            std::vector<cv::Vec3f> circles;
            cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT,1, gray.rows/16, threshold, 30, minRad, maxRad);
            size_t i;
            for(i=0;i<circles.size();i++){
                cv::Vec3i c = circles[i];
                cv::Point center = cv::Point(c[0], c[1]);
                cv::circle(frame, center,1, cv::Scalar(0, 100, 100), 2, cv::LINE_AA);
                int radius = c[2];
                cv::circle(frame, center,radius, cv::Scalar(0, 255, 0), 2, cv::LINE_AA);
            }
            char buff[256];
            std::sprintf(buff, "%d", i);
            QString s = buff;
            qDebug() << "Tutup botol : " << i;
            ui->label_7->setText(s);
            QImage img(
                        frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_BGR888);
            pixmap.setPixmap(QPixmap::fromImage(img.rgbSwapped()));
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }
    ui->pushButton->setText("Start");
}


void MainWindow::on_setVarBtn_clicked()
{
    threshold = ui->thresEdit->text().toUInt();
    minRad = ui->minRadEdit->text().toInt();
    maxRad = ui->MaxRadEdit->text().toInt();
    blur_coef = ui->MeanEdit->text().toInt();
}
