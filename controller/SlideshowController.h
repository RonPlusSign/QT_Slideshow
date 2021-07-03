//
// Created by andre on 28/06/21.
//

#ifndef QT_SLIDESHOW_SLIDESHOWCONTROLLER_H
#define QT_SLIDESHOW_SLIDESHOWCONTROLLER_H

#include <memory>
#include <model/ImageList.h>

class SlideshowController {
public:
    explicit SlideshowController(ImageList *imageList);

    void nextImage();
    void previousImage();
    void addImage(const std::string &imagePath);
    void clearImageList();
private:
    ImageList *imageList;
};


#endif //QT_SLIDESHOW_SLIDESHOWCONTROLLER_H
