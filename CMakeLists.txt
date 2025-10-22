cmake_minimum_required(VERSION 3.14)
project(sem3_lab3_c--)

#устанавливаем стандарт
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ЯВНО указываем где создавать исполняемый файл
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#основная программа
add_executable(main src/main.cpp)

#include директории
target_include_directories(main PRIVATE include)
