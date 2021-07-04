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
    std::shared_ptr<ImageList> imageList;
    std::unique_ptr<SlideshowController> controller;
    bool updated = false;

    void SetUp() override {
        imageList = std::make_shared<ImageList>();
        controller = std::make_unique<SlideshowController>(imageList);

        imageList->subscribe(this);
    }

    void TearDown() override {
        imageList->unsubscribe(this);
    }
};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    controller->addImage("a.png");
    ASSERT_TRUE(isUpdated());
}



