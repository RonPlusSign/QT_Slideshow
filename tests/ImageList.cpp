//
// Created by andre on 03/07/21.
//

#include <gtest/gtest.h>
#include "../model/ImageList.h"

TEST(ImageList, DefaultConstructor) {
    ImageList imageList;

    ASSERT_EQ(imageList.getImagesNumber(), 0);
}

TEST(ImageList, ParametrizedConstructor) {
    ImageList imageList({"a.png", "b.gif", "c.jpg", "d.jpeg"});

    ASSERT_EQ(imageList.getImagesNumber(), 4);
    ASSERT_EQ(imageList.getImagePath(0), "a.png");
    ASSERT_EQ(imageList.getImagePath(1), "b.gif");
    ASSERT_EQ(imageList.getImagePath(2), "c.jpg");
    ASSERT_EQ(imageList.getImagePath(3), "d.jpeg");
}

TEST(ImageList, Getters) {
    ImageList imageList({"a.png", "b.gif", "c.jpg", "d.jpeg"});

    ASSERT_EQ(imageList.getImagesNumber(), 4);
    ASSERT_EQ(imageList.getDisplayedImagePosition(), 0);
    ASSERT_EQ(imageList.getImagePath(0), "a.png");

    ASSERT_THROW(imageList.getImagePath(6), std::out_of_range);
}

TEST(ImageList, AddImage) {
    ImageList imageList({"a.png", "b.gif", "c.jpg", "d.jpeg"});

    imageList.addImage("e.png");
    ASSERT_EQ(imageList.getImagesNumber(), 5);
    ASSERT_EQ(imageList.getImagePath(4), "e.png");

    // Unsupported file format
    ASSERT_THROW(imageList.addImage("test.txt"), std::invalid_argument);
    ASSERT_EQ(imageList.getImagesNumber(), 5);
}

TEST(ImageList, Clear) {
    ImageList imageList({"a.png", "b.gif", "c.jpg", "d.jpeg"});

    imageList.clear();
    ASSERT_EQ(imageList.getImagesNumber(), 0);
}

TEST(ImageList, isValidImagePath) {
    ImageList imageList;

    ASSERT_TRUE(imageList.isValidImagePath("a.png"));
    ASSERT_TRUE(imageList.isValidImagePath("b.gif"));
    ASSERT_TRUE(imageList.isValidImagePath("c.jpg"));
    ASSERT_TRUE(imageList.isValidImagePath("d.jpeg"));

    ASSERT_FALSE(imageList.isValidImagePath("./f.txt"));
    ASSERT_FALSE(imageList.isValidImagePath("abcde"));
    ASSERT_FALSE(imageList.isValidImagePath(".jpegg"));
    ASSERT_FALSE(imageList.isValidImagePath(".jpg"));
}