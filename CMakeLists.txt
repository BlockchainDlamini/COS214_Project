cmake_minimum_required(VERSION 3.16)
project(Testing_links)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(Google_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Testing main.cpp Google_tests/test1.cpp Google_tests/test2.cpp main.cpp)

target_link_libraries(Testing gtest gtest_main)

file(GLOB SOURCES
        *.h
        *.cpp
        )

#add_executable(ClionProject ${SOURCE_FILES} ${SOURCES})

add_executable(Testing_links .code/main.cpp)