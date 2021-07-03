#include "ChooseFilesDialog.h"
#include "ui_ChooseFilesDialog.h"
#include <QFileDialog>


ChooseFilesDialog::ChooseFilesDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ChooseFilesDialog) {
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowTitle("Choose images");

    ui->confirmBtn->setEnabled(false);
}

ChooseFilesDialog::ChooseFilesDialog(ImageList *imageList, SlideshowController *controller, QWidget *parent) : ChooseFilesDialog(parent) {
    if (imageList == nullptr)
        throw std::invalid_argument("Invalid ImageList pointer received (ChooseFilesDialog)");
    this->imageList = imageList;
    mainWindow = nullptr;

    this->controller = controller;
}

ChooseFilesDialog::~ChooseFilesDialog() {
    delete ui;
}

void ChooseFilesDialog::on_chooseFilesBtn_clicked() {
    QString fileFilter = "Images (*.png *.jpg *.jpeg *.gif)";

    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Choose images", QDir::homePath(), fileFilter);

    QString filesList = "";
    for (const auto &file: fileNames)
        filesList.append(file + "\n");

    if (!fileNames.empty()) {
        controller->clearImageList();

        for (const auto &file: fileNames)
            controller->addImage(file.toStdString());

        ui->confirmBtn->setEnabled(true);
        ui->filesList->setText(filesList);
    }
}


void ChooseFilesDialog::on_confirmBtn_clicked() {
    if (mainWindow == nullptr)
        mainWindow = new MainWindow(controller, imageList, this);

    mainWindow->show();
    this->setVisible(false);
}

