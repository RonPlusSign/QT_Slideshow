#ifndef CHOOSEFILESDIALOG_H
#define CHOOSEFILESDIALOG_H

#include <QDialog>
#include <model/ImageList.h>
#include <controller/SlideshowController.h>
#include <components/SlideshowWindow/SlideshowWindow.h>

namespace Ui {
    class ChooseFilesDialog;
}

class ChooseFilesDialog : public QDialog {
Q_OBJECT

public:
    /**
     * Parametrized constructor
     * @param imageList model needed by the Slideshow window
     * @param controller Slideshow controller
     * @param parent QWidget parent widget
     */
    explicit ChooseFilesDialog(std::shared_ptr<ImageList> imageList, std::shared_ptr<SlideshowController> controller, QWidget *parent = nullptr);
    ~ChooseFilesDialog() override;

private slots:
    /**
     * "Choose files" button action
     */
    void on_chooseFilesBtn_clicked();

    /**
     * "Confirm" button action
     */
    void on_confirmBtn_clicked();

private:

    /**
     * Default QDialog constructor
     * @param parent QWidget parent widget
     */
    explicit ChooseFilesDialog(QWidget *parent = nullptr);

    Ui::ChooseFilesDialog *ui;
    std::shared_ptr<ImageList> imageList;
    std::shared_ptr<SlideshowController> controller;
    SlideshowWindow *mainWindow = nullptr;
};

#endif // CHOOSEFILESDIALOG_H
