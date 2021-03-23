cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(01-erste-schritte 01_erste_schritte/main.cpp Aufgaben/02/main.cpp)
add_executable(aufgabe-01 Aufgaben/01/test.cpp)
add_executable(aufgabe-02 Aufgaben/02/main.cpp)