cmake_minimum_required (VERSION 3.2)
project (roomed-game)

find_package (OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

set(SRC_LIST src/cpp/main.cpp
             src/cpp/world.cpp
             src/cpp/entity/entity.cpp
             src/cpp/render/render-main.cpp
             src/cpp/render/model-cache.cpp
             src/cpp/util/read-file.cpp)
set(LIB_LIST ${OPENGL_LIBRARY} GLEW glfw pthread) # g++ refuses to compile multithreaded code without pthread lib.

include_directories(src/h/)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})

add_subdirectory (src/google-test) # build google-test library.
add_subdirectory (src/tests) # build tests.
