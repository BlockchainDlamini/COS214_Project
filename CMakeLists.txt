cmake_minimum_required(VERSION 3.16)
project(Testing_links)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(Google_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Testing Google_tests/test1.cpp Google_tests/test2.cpp main.cpp)

file(GLOB SOURCES
        *.h
        *.cpp
        )

#add_executable(ClionProject ${SOURCE_FILES} ${SOURCES})

# Link the executable with gtest and gtest_main
target_link_libraries(Testing gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(Testing)
