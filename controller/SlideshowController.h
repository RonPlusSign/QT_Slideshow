//
// Created by andre on 28/06/21.
//

#ifndef QT_SLIDESHOW_SLIDESHOWCONTROLLER_H
#define QT_SLIDESHOW_SLIDESHOWCONTROLLER_H

#include <memory>
#include "../model/ImageList.h"

class SlideshowController {
public:
    /**
     * Parametrized constructor
     * @param imageList shared_ptr to the ImageList model
     */
    explicit SlideshowController(std::shared_ptr<ImageList> imageList);

    /**
     * Updates the model to go to the next image
     */
    void nextImage();

    /**
     * Updates the model to go to the previous image
     */
    void previousImage();

    /**
     * Adds an image to the model
     * @param imagePath (string) path to the image
     */
    void addImage(const std::string &imagePath);

    /**
     * Removes all elements from the model
     */
    void clearImageList();

private:
    std::shared_ptr<ImageList> imageList;
};


#endif //QT_SLIDESHOW_SLIDESHOWCONTROLLER_H
