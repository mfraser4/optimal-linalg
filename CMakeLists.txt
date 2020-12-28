cmake_minimum_required(VERSION 3.14)

project(
    "optimal-linalg"
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

message("\nStarted CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

#
# Prevent building in the source directory
#
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

if(${PROJECT_NAME}_ENABLE_DEBUG)
    add_compile_definitions(OPTIMAL_LINALG_DEBUG)
endif()

#
# Find all headers and implementation files
#
include(${CMAKE_SOURCE_DIR}/cmake/SourcesAndHeaders.cmake)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

#
# This project only builds as a library
#
add_library(
    ${PROJECT_NAME}
    ${headers}
    ${sources}
)

#
# Build tests if configured
#
if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
    enable_testing()
    message("Building unit tests.\n")
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()
