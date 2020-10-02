cmake_minimum_required(VERSION 3.18)
project(tncg15-raytracer)
find_package (Threads)

set(SOURCE_DIR "src")
set(INCLUDE_DIR "include")
set(BIN_DIR "bin")

set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS} -std=c++17 -g -pthread")
set(CMAKE_CXX_FLAGS_DEBUG_RELEASE "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "Build type not specified: Use Release by default")
endif(NOT CMAKE_BUILD_TYPE)

FILE(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp)
FILE(GLOB HEADER_FILES ${INCLUDE_DIR}/*.h)
include_directories(${INCLUDE_DIR})

find_package(glm REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/${BIN_DIR}/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/${BIN_DIR}/release")

add_executable(tncg15-raytracer ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries (tncg15-raytracer ${CMAKE_THREAD_LIBS_INIT})