cmake_minimum_required (VERSION 3.2)

project (tests)

set (SRC_LIST src/main.cpp)
include_directories (../google-test/include)
add_executable (run-tests ${SRC_LIST})

target_link_libraries (run-tests gtest gtest_main) 

