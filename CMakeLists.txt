cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(trace-it-now
    VERSION 1.0.0
    LANGUAGES CXX
)

set(HEADER_FILES
    src/core/Ray.hpp
    src/core/Vec3.hpp
    src/core/Camera.hpp
    src/core/Constants.hpp
    src/objects/Sphere.hpp
    src/HittableList.hpp
    src/Hittable.hpp
    src/Assert.hpp
)

set(SOURCE_FILES
    src/core/Vec3.cpp
    src/core/Camera.cpp
    src/objects/Sphere.cpp
    src/HittableList.cpp
    src/main.cpp
)

set(EXECUTABLE_NAME trace-it-now)
add_executable(${EXECUTABLE_NAME} ${HEADER_FILES} ${SOURCE_FILES})
