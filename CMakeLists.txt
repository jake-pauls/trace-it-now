cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(trace-it-now
    VERSION 1.0.0
    LANGUAGES CXX
)

set(SOURCE_FILES
    src/Assert.hpp
    src/main.cpp
)

set(EXECUTABLE_NAME trace-it-now)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})