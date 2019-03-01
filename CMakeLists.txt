cmake_minimum_required(VERSION 3.1)

project(FailTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)

set(PROJECT_SRC src/main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})