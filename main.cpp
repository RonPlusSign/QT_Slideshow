#include "MainWindow.h"

#include <QApplication>
#include <components/ChooseFilesDialog.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImageList model;

    QDialog *chooseFilesDialog = new ChooseFilesDialog(&model);
    chooseFilesDialog->show();

    SlideshowController controller(&model);
    MainWindow view(&controller, &model);

    view.show();
    return app.exec();
}
