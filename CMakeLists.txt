cmake_minimum_required (VERSION 3.2)
project (roomed-game)

# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
# find_package(Boost COMPONENTS filesystem REQUIRED)

set(SRC_LIST src/cpp/main.cpp)
include_directories(src/h/)
add_executable(${PROJECT_NAME} ${SRC_LIST})
# target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})


