cmake_minimum_required (VERSION 3.2)
project (roomed-game)

find_package (GLEW   REQUIRED)
find_package (OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

set(SRC_LIST src/cpp/main.cpp
             src/cpp/world.cpp
             src/cpp/world-updater.cpp
             src/cpp/entity/entity.cpp
             src/cpp/render/render-main.cpp
             src/cpp/render/model-cache.cpp
             src/cpp/render/shader-utils.cpp
             src/cpp/util/read-file.cpp)
set(LIB_LIST ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw pthread) # g++ refuses to compile multithreaded code without pthread lib.

include_directories(src/h/)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})

add_subdirectory (src/google-test) # build google-test library.
add_subdirectory (src/tests) # build tests.

add_custom_target(run-roomed-game-tests
                  DEPENDS roomed-game-tests-binary 
                  COMMAND ${CMAKE_BINARY_DIR}/src/tests/roomed-game-tests-binary
                  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_dependencies(roomed-game run-roomed-game-tests)
# we want our tests to be run, so we add this as dep.
# in fact, this appears fun, because tests are run before the entire project
# is built.
