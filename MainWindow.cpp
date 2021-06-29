#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), imageList(nullptr), controller(nullptr) { ui->setupUi(this); }

MainWindow::MainWindow(SlideshowController *controller, ImageList *imageList, QWidget *parent) : MainWindow(parent) {
    this->controller = controller;
    this->imageList = imageList;

    this->imageList->subscribe(this);
}

MainWindow::~MainWindow() {
    delete ui;
    this->imageList->unsubscribe(this);
}

void MainWindow::on_play_clicked() {

}

void MainWindow::on_next_clicked() {

}

void MainWindow::on_previous_clicked() {

}

void MainWindow::update() {

}

