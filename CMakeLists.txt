
cmake_minimum_required(VERSION 3.22)
project(Shipfind)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Shipfind ${SOURCES})
