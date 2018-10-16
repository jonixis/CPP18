cmake_minimum_required(VERSION 3.12)
project(61_PRPN)

set(CMAKE_CXX_STANDARD 17)

add_executable(61_PRPN main.cpp Fraction.cpp Fraction.h PRPN_calculator.h Persistence_traits.h Pvector.h)