cmake_minimum_required(VERSION 3.16)
project(Testing_links)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES
        *.h
        *.cpp
        )
add_executable(COS214_Project ${SOURCE_FILES} ${SOURCES})
