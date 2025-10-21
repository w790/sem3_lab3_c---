cmake_minimum_required(VERSION 3.14)
project(sem3_lab3_c--)

#устанавливаем стандарт
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#основная программа
add_executable(sem3_lab3_c-- src/main.cpp)

#include директории
target_include_directories(sem3_lab3_c-- PRIVATE include)
