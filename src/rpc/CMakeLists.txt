cmake_minimum_required(VERSION 3.5)

set(LIBRARY_NAME mylibrary)

file(GLOB SOURCES "*.cpp" "*.c")

add_library(${LIBRARY_NAME} STATIC ${SOURCES})