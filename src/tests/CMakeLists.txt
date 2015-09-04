cmake_minimum_required (VERSION 3.2)

project (roomed-game-tests-binary)

set (SRC_LIST src/aabb-test.cpp
              src/read-file-test.cpp
              ../cpp/util/read-file.cpp)
include_directories (../google-test/include)
include_directories (../h)

add_executable (roomed-game-tests-binary ${SRC_LIST})

target_link_libraries (roomed-game-tests-binary gtest gtest_main) 

