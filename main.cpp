
#include <QApplication>
#include <model/ImageList.h>
#include <controller/SlideshowController.h>
#include <components/ChooseFilesDialog.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImageList model;
    SlideshowController controller(&model);

    QDialog *chooseFilesDialog = new ChooseFilesDialog(&model, &controller);
    chooseFilesDialog->show();

    return app.exec();
}
