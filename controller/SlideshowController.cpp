//
// Created by andre on 28/06/21.
//

#include "SlideshowController.h"


SlideshowController::SlideshowController(std::shared_ptr<ImageList> imageList) : imageList(std::move(imageList)) {}

void SlideshowController::nextImage() {
    // If I'm at the end, restart from the first image
    if (imageList->getDisplayedImagePosition() + 1 == imageList->getImagesNumber())
        imageList->setDisplayedImagePosition(0);
    else
        imageList->setDisplayedImagePosition(imageList->getDisplayedImagePosition() + 1);
}

void SlideshowController::previousImage() {
    // If I'm at the first image, go to the last image
    if (imageList->getDisplayedImagePosition() == 0)
        imageList->setDisplayedImagePosition(imageList->getImagesNumber() - 1);
    else
        imageList->setDisplayedImagePosition(imageList->getDisplayedImagePosition() - 1);
}


void SlideshowController::addImage(const std::string &image) {
    imageList->addImage(image);
}

void SlideshowController::clearImageList() {
    imageList->clear();
}
