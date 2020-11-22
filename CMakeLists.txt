cmake_minimum_required(VERSION 3.15)
project(mydb1)

set(CMAKE_CXX_STANDARD 11)

add_executable(mydb1 main.cpp Meta.cpp Meta.h DataHandler.cpp DataHandler.h)