#ifndef CHOOSEFILESDIALOG_H
#define CHOOSEFILESDIALOG_H

#include <QDialog>
#include <model/ImageList.h>

namespace Ui {
    class ChooseFilesDialog;
}

class ChooseFilesDialog : public QDialog {
Q_OBJECT

public:
    explicit ChooseFilesDialog(ImageList *imageList, QWidget *parent = nullptr);
    ~ChooseFilesDialog() override;

private slots:
    void on_chooseFilesBtn_clicked();
    void on_confirmBtn_clicked();

private:
    explicit ChooseFilesDialog(QWidget *parent = nullptr);

    Ui::ChooseFilesDialog *ui;
    ImageList *imageList;
};

#endif // CHOOSEFILESDIALOG_H
