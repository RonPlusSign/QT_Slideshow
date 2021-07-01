#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <interfaces/Observer.h>
#include <controller/SlideshowController.h>
#include <model/ImageList.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    MainWindow(SlideshowController *controller, ImageList *imageList, QDialog *filesDialog, QWidget *parent = nullptr);
    ~MainWindow() override;

    void update() override;

private slots:
    void on_play_clicked();

    void on_next_clicked();

    void on_previous_clicked();

private:
    /**
     * Default QT Constructor
     * @param parent of the current Widget
     */
    explicit MainWindow(QWidget *parent);

    /**
     * Load & display the currently selected image
     */
    void renderImage();

    /**
     * Update the progress bar to display the correct level
     */
    void updateProgressBar();

    void startSlideshowTimer();

    Ui::MainWindow *ui;
    SlideshowController *controller;
    ImageList *imageList;
    QDialog *filesDialog;
    QTimer *timer;
};

#endif // MAINWINDOW_H
