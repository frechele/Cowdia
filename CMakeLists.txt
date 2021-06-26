# CMake version
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Declare project
project(Cowdia)

# Set c++ standard
set(CMAKE_CXX_STANDARD 17)

# Set output directories
set(DEFAULT_CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# Includes
include_directories(Includes)
include_directories(Libraries/doctest/doctest)

# Compile options
include(CMake/CompileOptions.cmake)

# Project modules
add_subdirectory(Sources/Cowdia)
add_subdirectory(Tests/UnitTests)
