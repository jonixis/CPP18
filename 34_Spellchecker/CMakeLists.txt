cmake_minimum_required(VERSION 3.12)
project(34_Spellchecker)

set(CMAKE_CXX_STANDARD 17)

file(GLOB src
    "src/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${src})