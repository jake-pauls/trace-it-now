cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(trace-it-now
    VERSION 1.0.0
    LANGUAGES CXX
)

set(HEADER_FILES
    src/core/ray.hpp
    src/core/vec3.hpp
    src/core/constants.hpp
    src/objects/sphere.hpp
    src/hittable_list.hpp
    src/hittable.hpp
    src/assert.hpp
)

set(SOURCE_FILES
    src/objects/sphere.cpp
    src/core/vec3.cpp
    src/hittable_list.cpp
    src/main.cpp
)

set(EXECUTABLE_NAME trace-it-now)
add_executable(${EXECUTABLE_NAME} ${HEADER_FILES} ${SOURCE_FILES})