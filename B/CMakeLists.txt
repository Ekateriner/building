cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)
project(B)

set(LIB_FILES "${PROJECT_SOURCE_DIR}/lib.cpp")

add_library(B SHARED ${LIB_FILES})