cmake_minimum_required(VERSION 3.5)

add_subdirectory(./googletest)
set(gtest_SOURCE_DIR, ./googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES run_tests.cpp ImageList.cpp SlideshowController.cpp ObserverPattern.cpp)
add_executable(Qt_Slideshow_Tests ${TEST_SOURCE_FILES})
target_link_libraries(Qt_Slideshow_Tests gtest gtest_main core)