cmake_minimum_required(VERSION 3.11)
project(Building)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Building_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${Building_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Building_SOURCE_DIR}/lib)

find_package(PythonInterp 3 REQUIRED)
set(PYTHON_EXECUTABLE "python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/A)
include_directories(${PROJECT_BINARY_DIR}/A)

add_custom_command(
    OUTPUT index.h
    COMMAND ${PYTHON_EXECUTABLE} ${Building_SOURCE_DIR}/A/preparing.py
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/A
    DEPENDS ${Building_SOURCE_DIR}/A/preparing.py
    COMMENT "Generating with python"
)

add_custom_target(
    RunGenerator
    DEPENDS index.h
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/A
    COMMENT "Checking if file generated"
)

include_directories(A ${Building_SOURCE_DIR})
add_subdirectory(B)

add_executable(Building C/main.cpp)

target_link_libraries(Building B)
add_dependencies(Building RunGenerator)
target_include_directories(Building PRIVATE ${CMAKE_BINARY_DIR})

include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${Building_SOURCE_DIR}/external)
ExternalProject_Add(
    googletest_repo
    GIT_REPOSITORY https://github.com/google/googletest.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(CTEST C/main-test.cpp C/tests.cpp)
target_link_libraries(CTEST B gtest pthread)
target_include_directories(CTEST PRIVATE ${CMAKE_BINARY_DIR})

