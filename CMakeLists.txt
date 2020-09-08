cmake_minimum_required(VERSION 3.16)
project(ExampleProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(LINK_OPENCV_SHARED_LIB "ON = Link OpenCV as a shared library. OFF = Link OpenCV as a static library." ON)

add_subdirectory(opencv)
add_subdirectory(example-app)
