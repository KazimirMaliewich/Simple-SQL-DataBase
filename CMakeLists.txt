cmake_minimum_required(VERSION 3.27)
project(DataBase2_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataBase2_0 main.cpp
        Table.cpp
        main.h
        DataBase.cpp)
