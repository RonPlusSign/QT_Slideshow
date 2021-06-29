#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <interfaces/Observer.h>
#include <controller/SlideshowController.h>
#include <model/ImageList.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    MainWindow(SlideshowController *controller, ImageList *imageList, QWidget *parent = nullptr);
    ~MainWindow() override;

    void update() override;

private slots:
    void on_play_clicked();

    void on_next_clicked();

    void on_previous_clicked();

private:
    explicit MainWindow(QWidget *parent);

    Ui::MainWindow *ui;
    SlideshowController *controller;
    ImageList *imageList;
};

#endif // MAINWINDOW_H
