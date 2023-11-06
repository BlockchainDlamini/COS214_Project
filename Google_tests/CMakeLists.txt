# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run test1.cpp test2.cpp)
add_test(NAME Google_Tests_ COMMAND Google_Tests_run)

target_link_libraries(Google_Tests_run gtest gtest_main)
