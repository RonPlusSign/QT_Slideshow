#include <QPixmap>
#include <QImageReader>
#include <iostream>
#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), imageList(nullptr), controller(nullptr), filesDialog(nullptr) {
    ui->setupUi(this);
    setWindowTitle("Image Slideshow");
}

MainWindow::MainWindow(SlideshowController *controller, ImageList *imageList, QDialog *filesDialog, QWidget *parent) : MainWindow(parent) {
    this->controller = controller;
    this->imageList = imageList;
    this->filesDialog = filesDialog;

    this->imageList->subscribe(this);

    // Set up the progress bar
    ui->progressBar->setRange(0, imageList->getImagesNumber());
    ui->progressBar->setFormat("%v/%m");
    updateProgressBar();

    // Load image
    if (this->imageList->getImagesNumber() > 0) {
        renderImage();
    }

    startSlideshowTimer();
}

MainWindow::~MainWindow() {
    delete ui;
    this->imageList->unsubscribe(this);
}

void MainWindow::on_play_clicked() {

}

void MainWindow::on_next_clicked() {
    delete timer;

    controller->nextImage();
    startSlideshowTimer();
}

void MainWindow::on_previous_clicked() {
    delete timer;

    controller->previousImage();
    startSlideshowTimer();
}

void MainWindow::update() {
    renderImage();
    updateProgressBar();
}

void MainWindow::renderImage() {
    QPixmap img(QString::fromStdString(this->imageList->getImagePath(this->imageList->getDisplayedImagePosition())));
    ui->image->setPixmap(img.scaled(img.size(), Qt::KeepAspectRatio));
}

void MainWindow::updateProgressBar() {
    ui->progressBar->setValue(imageList->getDisplayedImagePosition() + 1);
}

void MainWindow::startSlideshowTimer() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_next_clicked);
    timer->start(3000);
}
