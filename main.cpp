
#include <QApplication>
#include <model/ImageList.h>
#include <controller/SlideshowController.h>
#include <components/ChooseFilesDialog/ChooseFilesDialog.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto model = std::make_shared<ImageList>();
    auto controller = std::make_shared<SlideshowController>(model);

    ChooseFilesDialog chooseFilesDialog(model, controller);
    chooseFilesDialog.show();

    return app.exec();
}
