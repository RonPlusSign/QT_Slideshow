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
    /**
     * Parametrized constructor
     * @param controller shared_ptr to the slideshow controller
     * @param imageList shared_ptr to the model object
     * @param filesDialog ChooseFilesDialog unique_ptr (needed to restart the slideshow)
     * @param parent (QWidget) parent widget
     */
    SlideshowWindow(const std::shared_ptr<SlideshowController> &controller, const std::shared_ptr<ImageList> &imageList, QDialog *filesDialog, QWidget *parent = nullptr);

    ~SlideshowWindow() override;

    /**
     * Gets the updated data from the model and updates the view
     */
    void update() override;

private slots:

    /**
     * "Next" button action
     */
    void on_next_clicked();

    /**
     * "Previous" button action
     */
    void on_previous_clicked();

    /**
     * "Play/Pause" button action
     */
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
    void renderImage() const;

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
    std::shared_ptr<SlideshowController> controller = nullptr;
    std::shared_ptr<ImageList> imageList = nullptr;
    QDialog *filesDialog = nullptr;
    QTimer *timer = nullptr;
    bool isRunning = true;
};

#endif // SLIDESHOWWINDOW_H
