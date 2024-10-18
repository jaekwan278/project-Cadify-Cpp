cmake_minimum_required(VERSION 3.5.0)
project(CadifyCpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCASCADE REQUIRED)

set(SOURCES
     main.cpp
     lib/src/io-function.cpp
     lib/src/face-function.cpp
     lib/src/calc-function.cpp
     lib/src/point-function.cpp
     lib/src/align-function.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
include_directories(${OpenCASCADE_INCLUDE_DIR})

add_executable(CadifyCpp ${SOURCES})
target_link_libraries(CadifyCpp ${OpenCASCADE_LIBRARIES})