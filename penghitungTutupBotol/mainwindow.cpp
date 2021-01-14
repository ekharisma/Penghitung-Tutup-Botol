#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objdetection.h"
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
    ui->minRed->setText(QString::number(redMin));
    ui->maxRed->setText(QString::number(redMax));
    ui->minBlue->setText(QString::number(blueMin));
    ui->maxBlue->setText(QString::number(blueMax));
//    ui->minGreen->setText(QString::number(greenMin));
//    ui->maxGreen->setText(QString::number(greenMax));
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
            pixmap.setPixmap(QPixmap::fromImage(img));
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
            qDebug() << "Main";
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
    while (video.isOpened()) {
        video >> frame;
        if (! frame.empty()){
            cvtColor(frame, hsv, COLOR_BGR2HSV);
            Mat lower_red_hue_range, upper_red_hue_range;
            Mat red_hue_image;
            qDebug() << "Test";
            inRange(hsv, Scalar(redMin, 100, 100), Scalar(10, 255, 255), lower_red_hue_range);
            inRange(hsv, Scalar(160, 100, 100), Scalar(redMax, 255, 255), upper_red_hue_range);
            addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);
            GaussianBlur(red_hue_image, red_hue_image, Size(9, 9), 2, 2);
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
            Mat blue_hue_image;
            inRange(hsv, Scalar(blueMin, 80, 2), Scalar(blueMax, 255, 255), blue_hue_image);
            qDebug() << "Test";
            GaussianBlur(blue_hue_image, blue_hue_image, Size(9, 9), 2, 2);
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
            inRange(hsv, Scalar(whiteMin, 0, 212), Scalar(whiteMax, 255, 255), white_hue_image);
            qDebug() << "Test";
            GaussianBlur(white_hue_image, white_hue_image, Size(9, 9), 2, 2);
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

//            Mat green_hue_image;
//            inRange(hsv, Scalar(greenMin, 0, 212), Scalar(greenMax, 255, 255), green_hue_image);
//            qDebug() << "Test";
//            GaussianBlur(green_hue_image, green_hue_image, Size(9, 9), 2, 2);
//            std::vector<Vec3f> circles3;
//            HoughCircles(green_hue_image, circles3, HOUGH_GRADIENT, 1,
//                         green_hue_image.rows/16,  // change this value to detect circles with different distances to each other
//                         threshold, 30, minRad, maxRad // change the last two parameters
//                         // (min_radius & max_radius) to detect larger circles
//                         );
//            size_t m;
//            for(m = 0; m < circles3.size(); m++ )
//            {
//                Vec3i e = circles3[m];
//                Point center3 = Point(e[0], e[1]);
//                // circle center
//                circle( frame, center3, 1, Scalar(0,100,100), 2, LINE_AA);
//                // circle outline
//                int radius3 = e[2];
//                circle( frame, center3, radius3, Scalar(0,255,0), 2, LINE_AA);
//            }
            char red[256];
            char blue[256];
            char white[256];
//            char green[256];
            char total_lab[256];
            int total = i + j + k;
            std::sprintf(total_lab, "%d", total);
            std::sprintf(red, "%d", i);
            std::sprintf(blue, "%d", j);
            std::sprintf(white, "%d", k);
//            std::sprintf(green, "%d", m);
            QString red_label = red;
            QString blue_label = blue;
//            QString green_label = green;
            QString white_label = white;
            ui->label_7->setText(total_lab);
            ui->redLabel->setText(red_label);
            ui->blueLabel->setText(blue_label);
//            ui->greenLabel->setText(green_label);
            ui->whiteLabel->setText(white_label);
            QImage img(
                        frame.data,
                        frame.cols,
                        frame.rows,
                        frame.step,
                        QImage::Format_BGR888);
            pixmap.setPixmap(QPixmap::fromImage(img));
            ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
            qDebug() << "Main";
        }
        qApp->processEvents();
    }
    //    ui->pushButton->setText("Start");
    ui->bedaWarnaBtn->setText("Beda Warna");
}
