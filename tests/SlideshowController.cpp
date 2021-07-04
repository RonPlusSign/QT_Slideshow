//
// Created by andre on 04/07/21.
//

#include <gtest/gtest.h>
#include "../model/ImageList.h"
#include "../controller/SlideshowController.h"

class SlideshowControllerTest : public testing::Test {
protected:
    std::unique_ptr<SlideshowController> controller;
    ImageList *imageList;

    void SetUp() override {
        imageList = new ImageList({"a.png", "b.gif", "c.jpg", "d.jpeg"});
        controller = std::make_unique<SlideshowController>(imageList);
    }

    void TearDown() override {
        delete imageList;
    }
};

TEST_F(SlideshowControllerTest, AddImage) {
    controller->addImage("e.png");

    ASSERT_EQ(imageList->getImagesNumber(), 5);
    ASSERT_EQ(imageList->getImagePath(4), "e.png");
}

TEST_F(SlideshowControllerTest, NextImage) {
    // Simple forward update
    imageList->setDisplayedImagePosition(0);
    controller->nextImage();
    ASSERT_EQ(imageList->getDisplayedImagePosition(), 1);

    // If I'm at the last image, to to the first one
    imageList->setDisplayedImagePosition(imageList->getImagesNumber() - 1);
    controller->nextImage();
    ASSERT_EQ(imageList->getDisplayedImagePosition(), 0);
}

TEST_F(SlideshowControllerTest, PreviousImage) {
    // Simple backward update
    imageList->setDisplayedImagePosition(1);
    controller->previousImage();
    ASSERT_EQ(imageList->getDisplayedImagePosition(), 0);

    // If I'm at the first image, to to the last one
    imageList->setDisplayedImagePosition(0);
    controller->previousImage();
    ASSERT_EQ(imageList->getDisplayedImagePosition(), imageList->getImagesNumber() - 1);
}

TEST_F(SlideshowControllerTest, ClearImageList) {
    controller->clearImageList();
    ASSERT_EQ(imageList->getImagesNumber(), 0);
}

