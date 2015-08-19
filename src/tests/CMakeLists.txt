cmake_minimum_required (VERSION 3.2)

project (tests)

set (SRC_LIST src/aabb-test.cpp
              src/read-file-test.cpp
              ../cpp/util/read-file.cpp)
include_directories (../google-test/include)
include_directories (../h)
add_executable (run-tests ${SRC_LIST})

target_link_libraries (run-tests gtest gtest_main) 

