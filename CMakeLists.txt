cmake_minimum_required(VERSION 3.28)
project(xyMath C)

set(CMAKE_C_STANDARD 11)

add_library(xyMath STATIC src/xymath.c
        src/xymath.h
        src/basic.h
        src/basic.c
        src/matrix.h
        src/matrix.c
        src/determinant.c
        src/determinant.h
)


