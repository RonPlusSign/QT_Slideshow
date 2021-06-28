//
// Created by andre on 28/06/21.
//

#include <stdexcept>
#include <fstream>
#include "ImageList.h"

static const std::vector<std::string> SUPPORTED_EXTENSIONS{".jpg", ".jpeg", ".png", ".gif"};


ImageList::ImageList(const std::vector<std::string> &filePaths) {
    imagesPath.reserve(filePaths.size());

    for (const auto &imagePath: filePaths)
        addImage(imagePath);
}


ImageList::ImageList(const ImageList &other) : ImageList(other.imagesPath) {}


std::string ImageList::getImagePath(int position) {
    if (position < 0 || position >= imagesPath.size())
        throw std::out_of_range("Invalid image position.");
    return imagesPath[position];
}


int ImageList::getImagesNumber() {
    return imagesPath.size();
}


void ImageList::addImage(const std::string &imagePath) {
    if (isValidImagePath(imagePath))
        imagesPath.push_back(imagePath);
    else
        throw std::invalid_argument("Invalid image path.");
}

bool ImageList::isValidImagePath(const std::string &path) {
    std::ifstream file(path);

    // File name is not empty and file exists
    if (path.empty() || !file.good()) return false;

    // Check if the file has a supported extension
    for (const auto &extension: SUPPORTED_EXTENSIONS)
        if (endsWith(path, extension))
            return true;

    return false;
}
