cmake_minimum_required(VERSION 3.10)
project(Lab4Number2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyExecutable TextFileProcessor.h main.cpp TextFileProcessor.cpp)