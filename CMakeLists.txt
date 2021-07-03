cmake_minimum_required(VERSION 3.5)

project(QT_Slideshow VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH D:\\QT\\5.15.2\\mingw81_64)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        components/SlideshowWindow/SlideshowWindow.cpp components/SlideshowWindow/SlideshowWindow.h components/SlideshowWindow/SlideshowWindow.ui
        components/ChooseFilesDialog/ChooseFilesDialog.h components/ChooseFilesDialog/ChooseFilesDialog.cpp components/ChooseFilesDialog/ChooseFilesDialog.ui
        controller/SlideshowController.cpp controller/SlideshowController.h
        model/ImageList.cpp model/ImageList.h
        interfaces/Subject.h interfaces/Observer.h
        )


add_executable(QT_Slideshow main.cpp)

add_library(core ${PROJECT_SOURCES})
target_link_libraries(core Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(QT_Slideshow core)

add_subdirectory(tests)

set_target_properties(QT_Slideshow PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )
