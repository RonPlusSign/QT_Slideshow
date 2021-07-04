//
// Created by andre on 04/07/21.
//

#include <gtest/gtest.h>
#include "../model/ImageList.h"
#include "../interfaces/Observer.h"
#include "../controller/SlideshowController.h"


class ObserverTest : public testing::Test, public Observer {
public:
    void update() override {
        updated = true;
    }

    bool isUpdated() const {
        return updated;
    }

protected:
    ImageList *imageList;
    std::unique_ptr<SlideshowController> controller;
    bool updated;

    void SetUp() override {
        imageList = new ImageList();
        controller = std::make_unique<SlideshowController>(imageList);

        imageList->subscribe(this);
        updated = false;
    }

    void TearDown() override {
        imageList->unsubscribe(this);
        delete imageList;
    }
};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    controller->addImage("a.png");
    ASSERT_TRUE(isUpdated());
}



