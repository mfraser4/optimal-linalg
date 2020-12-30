cmake_minimum_required(VERSION 3.14)

project("optimal-linalg")

add_executable(optimal-linalg-test
    ../include/linalg.h
    ../src/linalg.cpp
    optimal-linalg-test.cpp
    test-compile-time-expressions.cpp
)

set_target_properties(optimal-linalg-test PROPERTIES
    CXX_STANDARD 14
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)
