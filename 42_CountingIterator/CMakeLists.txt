cmake_minimum_required(VERSION 3.12)
project(42_CountingIterator)

set(CMAKE_CXX_STANDARD 17)

file(GLOB src
    "src/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${src})