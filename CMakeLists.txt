cmake_minimum_required(VERSION 3.10)

project(kde_headsetcontrol_integration LANGUAGES CXX VERSION 1.0)

# CMake configuration
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TEST_PROJECT "Test project to test the functionality" ON)

# Dependencies
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Test project
if(BUILD_TEST_PROJECT)
    add_subdirectory(test_project)
endif()

# QML module
add_subdirectory(module)
