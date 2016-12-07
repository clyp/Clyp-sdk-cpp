cmake_minimum_required(VERSION 3.6)
project(Clyp_sdk_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp clyp.cpp clyp.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_executable(Clyp_sdk_cpp ${SOURCE_FILES})