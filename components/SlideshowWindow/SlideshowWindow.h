#ifndef SLIDESHOWWINDOW_H
#define SLIDESHOWWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <interfaces/Observer.h>
#include <controller/SlideshowController.h>
#include <model/ImageList.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SlideshowWindow; }
QT_END_NAMESPACE

class SlideshowWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    SlideshowWindow(SlideshowController *controller, ImageList *imageList, QDialog *filesDialog, QWidget *parent = nullptr);
    ~SlideshowWindow() override;

    void update() override;

private slots:

    void on_next_clicked();

    void on_previous_clicked();

    void on_togglePlayPause_clicked();

private:
    /**
     * Default QT Constructor
     * @param parent of the current Widget
     */
    explicit SlideshowWindow(QWidget *parent);

    /**
     * Load & display the currently selected image
     */
    void renderImage();

    /**
     * Update the progress bar to display the correct level
     */
    void updateProgressBar();

    /**
     * Start a new QTimer to scroll images
     */
    void startSlideshowTimer();

    /**
     * Override the QMainWindow showEvent attribute in order to display the first image properly
     * @param event QShowEvent triggered when show() is called
     */
    void showEvent(QShowEvent *event) override;

    Ui::SlideshowWindow *ui;
    SlideshowController *controller;
    ImageList *imageList;
    QDialog *filesDialog;
    QTimer *timer;
    bool isRunning;
};

#endif // SLIDESHOWWINDOW_H
