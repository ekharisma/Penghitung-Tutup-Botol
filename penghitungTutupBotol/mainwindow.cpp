#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addItem(&pixmap);
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
    cv::Mat frame;
    while (video.isOpened()) {
        video >> frame;
        if (! frame.empty()){
            QImage img(
                        frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_RGB888);
            pixmap.setPixmap(QPixmap::fromImage(img.rgbSwapped()));
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }
    ui->pushButton->setText("Start");
}
