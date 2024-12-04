cmake_minimum_required(VERSION 3.5)
project(rpcServer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
include_directories("${PROJECT_SOURCE_DIR}/include/rpc")
include_directories("${PROJECT_SOURCE_DIR}/include/rpc/serviceRegistrationCente")
include_directories("${PROJECT_SOURCE_DIR}/third_party/include")

link_directories("${PROJECT_SOURCE_DIR}/third_party/lib/muduo")
link_directories("${PROJECT_SOURCE_DIR}/third_party/lib/oneTBB")
add_subdirectory(src)