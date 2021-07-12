//
// Created by andre on 28/06/21.
//

#ifndef QT_SLIDESHOW_IMAGELIST_H
#define QT_SLIDESHOW_IMAGELIST_H

#include <string>
#include <vector>
#include "../interfaces/Subject.h"
#include "../utils/utils.h"

/**
 * Class that handles a list of image paths
 */
class ImageList : public Subject {
public:

    /**
     * Default constructor
     */
    ImageList() = default;

    /**
     * Parametrized constructor
     * @param filePaths vector containing the image paths
     */
    explicit ImageList(const std::vector<std::string> &filePaths);

    /**
     * Copy constructor
     * @param other (ImageList) The other ImageList to copy
     */
    ImageList(const ImageList &other);

    /**
     * Gets the path of a file at a specific index
     * @param position (int) indicates which image path to get
     * @return (string) The image path
     * @throws out_of_range if the position is invalid
     */
    std::string getImagePath(int position) const;


    /**
     * Gets the number of imagesPath inside the list
     * @return (int) Number of imagesPath inside the list
     */
    int getImagesNumber() const;


    /**
     * Adds an image path inside the list of image paths
     * @param imagePath (string) Image path to add
     */
    void addImage(const std::string &imagePath);


    /**
     * Checks if an image exists, and it has a valid extension
     * @param path (string) Image path to be tested
     * @return (bool) True if the image path is valid, false otherwise
     */
    static bool isValidImagePath(const std::string &path);

    /**
     * Notify all Observers
     */
    void notify() const override;

    /**
     * Removes all the images inside the list
     */
    void clear();

    /**
     * Get the currently displayed image position
     * @return (string) The currently displayed image position
     */
    int getDisplayedImagePosition() const;

    /**
     * Sets the currently displayed image position
     * @param imagePosition (int) Image position
     */
    void setDisplayedImagePosition(int imagePosition);

private:
    std::vector<std::string> imagesPath;
    int displayedImagePosition{0};

    static const std::vector<std::string> SUPPORTED_EXTENSIONS;
};


#endif //QT_SLIDESHOW_IMAGELIST_H
