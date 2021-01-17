cmake_minimum_required(VERSION 3.14)

project("optimal-linalg")

find_package(PkgConfig REQUIRED)
pkg_search_module(CPPUTEST REQUIRED cpputest >= 3.8)

set(PROJECT_NAME_TEST ${PROJECT_NAME}-test)

set(TEST_SOURCES
    test-compile-time-expressions.cpp
    test-matrix-operations.cpp
    optimal-linalg-test.cpp
)

include_directories(
    ${CPPUTEST_INCLUDE_DIRS}
    ../include
)
link_directories(${CPPUTEST_LIBRARIES})

add_executable(${PROJECT_NAME_TEST}
    ${TEST_SOURCES}
)
target_link_libraries(${PROJECT_NAME_TEST} ${PROJECT_NAME} ${CPPUTEST_LDFLAGS})

set_target_properties(${PROJECT_NAME_TEST} PROPERTIES
    CXX_STANDARD 14
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)
