#include <QPixmap>
#include <QImageReader>
#include <iostream>
#include "SlideshowWindow.h"
#include "./ui_SlideshowWindow.h"

SlideshowWindow::SlideshowWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SlideshowWindow) {
    ui->setupUi(this);
    setWindowTitle("Image Slideshow");
}

SlideshowWindow::SlideshowWindow(const std::shared_ptr<SlideshowController> &controller, const std::shared_ptr<ImageList> &imageList, QDialog *filesDialog, QWidget *parent)
        : SlideshowWindow(parent) {
    this->controller = controller;
    this->imageList = imageList;
    this->filesDialog = filesDialog;

    this->imageList->subscribe(this);

    // Set up the progress bar
    ui->progressBar->setRange(0, imageList->getImagesNumber());
    updateProgressBar();

    startSlideshowTimer();
}

SlideshowWindow::~SlideshowWindow() {
    delete ui;
    this->imageList->unsubscribe(this);
}

void SlideshowWindow::on_togglePlayPause_clicked() {
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

void SlideshowWindow::on_next_clicked() {
    controller->nextImage();

    if (isRunning)
        startSlideshowTimer();
}

void SlideshowWindow::on_previous_clicked() {
    controller->previousImage();

    if (isRunning)
        startSlideshowTimer();
}

void SlideshowWindow::update() {
    renderImage();
    updateProgressBar();
}

void SlideshowWindow::renderImage() const {
    QPixmap img(QString::fromStdString(this->imageList->getImagePath(this->imageList->getDisplayedImagePosition())));
    ui->image->setPixmap(img.scaled(ui->image->size(), Qt::KeepAspectRatio));
}

void SlideshowWindow::updateProgressBar() {
    ui->progressBar->setValue(imageList->getDisplayedImagePosition() + 1);
}

void SlideshowWindow::startSlideshowTimer() {
    if (timer != nullptr) {
        delete timer;
        timer = nullptr;
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SlideshowWindow::on_next_clicked);
    timer->start(3000);
    timer->setSingleShot(true);
}

void SlideshowWindow::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    renderImage();
}
