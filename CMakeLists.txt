cmake_minimum_required(VERSION 3.27)
project(SDL_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_APPLE_SILICON_PROCESSOR arm64) # comment out for linux builds
file (GLOB_RECURSE SDL_test_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE SDL_test_SOURCES_DEEP CONFIGURE_DEPENDS "src/*/*.cpp")

link_directories(
        /opt/homebrew/Cellar/sdl2/2.30.0/lib
        /opt/homebrew/Cellar/sdl2_image/2.8.2/lib
)
add_executable("${CMAKE_PROJECT_NAME}" ${SDL_test_SOURCES} ${SDL_test_SOURCES_DEEP} src/main.cpp)

set(SDL_test_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_definitions(
        -DWINDOW_NAME="SDL Test"
        -DWINDOW_WIDTH=800
        -DWINDOW_HEIGHT=600
)

target_link_libraries(
        "${CMAKE_PROJECT_NAME}"
        libSDL2-2.0.0.dylib
        libSDL2_image-2.0.0.dylib
)

target_include_directories(
        "${CMAKE_PROJECT_NAME}"
        PUBLIC SDL_test_HEADERS
        PUBLIC /opt/homebrew/Cellar/sdl2/2.30.0/include/SDL2
        PUBLIC /opt/homebrew/Cellar/sdl2_image/2.8.2/include/SDL2
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/core
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/scene
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/serializer
)