#include <QPixmap>
#include <QImageReader>
#include <iostream>
#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          ui(new Ui::MainWindow),
          imageList(nullptr),
          controller(nullptr),
          filesDialog(nullptr),
          timer(nullptr),
          isRunning(true) {
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
    updateProgressBar();

    startSlideshowTimer();
}

MainWindow::~MainWindow() {
    delete ui;
    this->imageList->unsubscribe(this);
}

void MainWindow::on_togglePlayPause_clicked() {
    if (isRunning) {
        ui->togglePlayPause->setText("►");
        delete timer;
        timer = nullptr;
    } else {
        ui->togglePlayPause->setText("❚❚");
        startSlideshowTimer();
    }
    isRunning = !isRunning;
}

void MainWindow::on_next_clicked() {
    controller->nextImage();

    if (isRunning)
        startSlideshowTimer();
}

void MainWindow::on_previous_clicked() {
    controller->previousImage();

    if (isRunning)
        startSlideshowTimer();
}

void MainWindow::update() {
    renderImage();
    updateProgressBar();
}

void MainWindow::renderImage() {
    QPixmap img(QString::fromStdString(this->imageList->getImagePath(this->imageList->getDisplayedImagePosition())));
    ui->image->setPixmap(img.scaled(ui->image->size(), Qt::KeepAspectRatio));
}

void MainWindow::updateProgressBar() {
    ui->progressBar->setValue(imageList->getDisplayedImagePosition() + 1);
}

void MainWindow::startSlideshowTimer() {
    if (timer != nullptr) {
        delete timer;
        timer = nullptr;
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_next_clicked);
    timer->start(3000);
    timer->setSingleShot(true);
}

void MainWindow::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    renderImage();
}
