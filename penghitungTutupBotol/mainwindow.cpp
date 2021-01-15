#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objdetection.h"
#include "unistd.h"

#include <QFileDialog>

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
    ui->minRed->setText(QString::number(redMin));
    ui->maxRed->setText(QString::number(redMax));
    ui->minBlue->setText(QString::number(blueMin));
    ui->maxBlue->setText(QString::number(blueMax));
    ui->minWhite->setText(QString::number(whiteMin));
    ui->maxWhite->setText(QString::number(whiteMax));
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

void MainWindow::on_setVarBtn_clicked()
{
    threshold = ui->thresEdit->text().toUInt();
    minRad = ui->minRadEdit->text().toInt();
    maxRad = ui->MaxRadEdit->text().toInt();
    blur_coef = ui->MeanEdit->text().toInt();
}

void MainWindow::on_warna1Btn_clicked()
{
    if (video.isOpened()){
        //        ui->pushButton->setText("Start");
        ui->warna1Btn->setText("1 Warna");
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
    //    ui->pushButton->setText("Stop");
    ui->warna1Btn->setText("Stop");
    cv::Mat frame, gray;
    float stabilizer = 0;
    float divider = 0;
    float stabilized_value;
    while (video.isOpened()) {
        video >> frame;
        if (! frame.empty()){
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::GaussianBlur(gray, gray, cv::Size(blur_coef, blur_coef), 3, 3);
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
            if (stabilizer <= 100) {
                stabilizer += i;
                divider ++;
            }
            else {
                stabilized_value = stabilizer / divider;
                stabilizer = divider = 0;
            }
            total_bottle = QString::number(ceil(stabilized_value));
            red_label = "0";
            blue_label = "0";
            white_label = "0";
            ui->label_7->setText(total_bottle);
            ui->redLabel->setText(red_label);
            ui->blueLabel->setText(blue_label);
            ui->whiteLabel->setText(white_label);
            QImage img(
                        frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_BGR888);
            pixmap.setPixmap(QPixmap::fromImage(img));
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }
    //    ui->pushButton->setText("Start");
    ui->warna1Btn->setText("Start");
}
void MainWindow::on_bedaWarnaBtn_clicked()
{
    if (video.isOpened()){
        //        ui->pushButton->setText("Start");
        ui->bedaWarnaBtn->setText("Beda Warna");
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
    //    ui->pushButton->setText("Stop");
    ui->bedaWarnaBtn->setText("Stop");
    cv::Mat frame, hsv;
    float stable_red = 0, stable_blue = 0, stable_white = 0;
    float red_stabilizer, blue_stabilizer, white_stabilizer, red_divider, blue_divider, white_divider;
    red_stabilizer = blue_stabilizer = white_stabilizer = red_divider = blue_divider = white_divider = 0;
    while (video.isOpened()) {
        video >> frame;
        if (! frame.empty()){
            cvtColor(frame, hsv, COLOR_BGR2HSV);
            Mat lower_red_hue_range;
            Mat upper_red_hue_range;
            inRange(hsv, Scalar(redMin, 120, 70), Scalar(10, 255, 255), lower_red_hue_range);
            inRange(hsv, Scalar(160, 120, 70), Scalar(redMax, 255, 255), upper_red_hue_range);
            Mat red_hue_image;
            addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);
            GaussianBlur(red_hue_image, red_hue_image, Size(blur_coef, blur_coef), 2, 2);
            std::vector<Vec3f> circles;
            HoughCircles(red_hue_image, circles, HOUGH_GRADIENT, 1,
                         red_hue_image.rows/16,  // change this value to detect circles with different distances to each other
                         threshold, 30, minRad, maxRad // change the last two parameters
                         // (min_radius & max_radius) to detect larger circles
                         );
            size_t i;
            for(i = 0; i < circles.size(); i++ )
            {
                Vec3i c = circles[i];
                Point center = Point(c[0], c[1]);
                // circle center
                circle( frame, center, 1, Scalar(0,100,100), 2, LINE_AA);
                // circle outline
                int radius = c[2];
                circle( frame, center, radius, Scalar(0,255,0), 2, LINE_AA);
            }

            qDebug() << i;
            Mat blue_hue_image;
            inRange(hsv, Scalar(105, 83, 0), Scalar(130, 255, 255), blue_hue_image);
            GaussianBlur(blue_hue_image, blue_hue_image, Size(blur_coef, blur_coef), 2, 2);
            std::vector<Vec3f> circles1;
            HoughCircles(blue_hue_image, circles1, HOUGH_GRADIENT, 1,
                         blue_hue_image.rows/16,  // change this value to detect circles with different distances to each other
                         threshold, 30, minRad, maxRad // change the last two parameters
                         // (min_radius & max_radius) to detect larger circles
                         );
            size_t j;
            for(j = 0; j < circles1.size(); j++ )
            {
                Vec3i cc = circles1[j];
                Point center1 = Point(cc[0], cc[1]);
                // circle center
                circle( frame, center1, 1, Scalar(0,100,100), 2, LINE_AA);
                // circle outline
                int radius1 = cc[2];
                circle( frame, center1, radius1, Scalar(0,255,0), 2, LINE_AA);
            }

            Mat white_hue_image;
            inRange(hsv, Scalar(whiteMin, 0, 205), Scalar(whiteMax, 35, 255), white_hue_image);
            GaussianBlur(white_hue_image, white_hue_image, Size(9, 9), 2, 2);
            //medianBlur(red_hue_image, red_hue_image, 5);
            std::vector<Vec3f> circles2;
            HoughCircles(white_hue_image, circles2, HOUGH_GRADIENT, 1,
                         white_hue_image.rows/16,  // change this value to detect circles with different distances to each other
                         threshold, 30, minRad, maxRad // change the last two parameters
                         // (min_radius & max_radius) to detect larger circles
                         );
            size_t k;
            for(k = 0; k < circles2.size(); k++ )
            {
                Vec3i d = circles2[k];
                Point center2 = Point(d[0], d[1]);
                // circle center
                circle( frame, center2, 1, Scalar(0,100,100), 2, LINE_AA);
                // circle outline
                int radius2 = d[2];
                circle( frame, center2, radius2, Scalar(0,255,0), 2, LINE_AA);
            }

            if (red_stabilizer <= 10) {
                red_stabilizer += i;
                red_divider ++;
            }
            else {
                stable_red = red_stabilizer / red_divider;
                red_stabilizer = red_divider = 0;
            }

            if (blue_stabilizer <= 10) {
                blue_stabilizer += j;
                blue_divider ++;
            }
            else {
                stable_blue = blue_stabilizer / blue_divider;
                blue_stabilizer = blue_divider = 0;
            }

            if (white_stabilizer <= 10) {
                white_stabilizer += k;
                white_divider ++;
            }
            else {
                stable_white = white_stabilizer / white_divider;
                white_stabilizer = white_divider = 0;
            }


            int total = ceil(stable_red + stable_blue + stable_white);
            total_bottle = QString::number(ceil(total));
            red_label = QString::number(ceil(stable_red));
            blue_label = QString::number(ceil(stable_blue));
            white_label = QString::number(ceil(stable_white));
            ui->label_7->setText(total_bottle);
            ui->redLabel->setText(red_label);
            ui->blueLabel->setText(blue_label);
            ui->whiteLabel->setText(white_label);
            QImage img(
                        frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_BGR888);
            pixmap.setPixmap(QPixmap::fromImage(img));
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
        }
        qApp->processEvents();
    }
    //    ui->pushButton->setText("Start");
    ui->bedaWarnaBtn->setText("Beda Warna");
}

void MainWindow::on_pushButton_clicked()
{
    QString outDir = QFileDialog::getSaveFileName(
                this,
                tr("Simpan dimana ?"),
                tr("Pembacaan :")
                );
    if (outDir.isEmpty()) return;
    else {
        QFile file(outDir);
        if (!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this, tr("Tidak bisa dibuka"), file.errorString());
            return;
        }
        QTextStream outFile(&file);
        outFile << "Jumlah botol :";
        outFile << total_bottle;
        outFile << "\n";
        outFile << "Botol merah :";
        outFile << red_label;
        outFile << "\n";
        outFile << "Botol Biru:";
        outFile << blue_label;
        outFile << "\n";
        outFile << "Botol Putih : ";
        outFile << white_label;
        outFile << "\n";
    }
}
