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

# 3rd-party
include_directories(Libraries/doctest/doctest)
include_directories(Libraries/entt/single_include)

# Includes
include_directories(Includes)

# Compile options
include(CMake/CompileOptions.cmake)

# Project modules
add_subdirectory(Sources/Cowdia)
add_subdirectory(Tests/UnitTests)

# Plugins
if(WIN32)
add_subdirectory(Extensions/D3D12Renderer)
endif()

# Applications
add_subdirectory(Extensions/TestApp)
