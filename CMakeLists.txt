cmake_minimum_required(VERSION 3.10)

# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fsigned-char -Wall -Wextra -Wpedantic -Woverloaded-virtual -Wno-unknown-pragmas -Wno-enum-compare")
project(prj_inf1015)

file(GLOB ALL_FILES
    *.cpp
    *.hpp
)

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE "include")