#include "ChooseFilesDialog.h"
#include "ui_ChooseFilesDialog.h"
#include <QFileDialog>


ChooseFilesDialog::ChooseFilesDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ChooseFilesDialog), imageList(nullptr) {
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

ChooseFilesDialog::ChooseFilesDialog(ImageList *imageList, QWidget *parent) : ChooseFilesDialog(parent) {
    if (imageList == nullptr)
        throw std::invalid_argument("Invalid ImageList pointer received (ChooseFilesDialog)");
    this->imageList = imageList;
}

ChooseFilesDialog::~ChooseFilesDialog() {
    delete ui;
}

void ChooseFilesDialog::on_chooseFilesBtn_clicked() {
    QString fileFilter = "Images (*.png *.jpg *.jpeg *.gif)";

    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Choose images", QDir::homePath(), fileFilter);

    for (const auto &file: fileNames)
        imageList->addImage(file.toStdString());

    // TODO: Enable OK Button

    // TODO: Send the result to the mainWindow
}


void ChooseFilesDialog::on_confirmBtn_clicked() {
    // TODO: Check if files are valid
}

