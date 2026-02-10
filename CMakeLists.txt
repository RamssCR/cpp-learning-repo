cmake_minimum_required(VERSION 4.0)
project(MyFirstCppApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
        MyFirstCppApp main.cpp
        src/song.cpp
        src/library.cpp
        src/playlist.cpp
        src/active_player.cpp
)
target_include_directories(MyFirstCppApp PUBLIC include)

target_compile_options(MyFirstCppApp PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -g
        -O0
)