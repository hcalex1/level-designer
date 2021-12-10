cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(prj_inf1015)

file(GLOB ALL_FILES
    *.cpp
    *.hpp
    *.h
)

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE "include")