cmake_minimum_required(VERSION 3.10)

project(TEMPLATE_PILE_SHARED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(Pile SHARED Pile.cpp Pile.h TestPPile.cpp TestPPile.h)

add_executable(TEMPLATE_PILE_SHARED main.cpp)

target_link_libraries(TEMPLATE_PILE_SHARED PRIVATE Pile)

