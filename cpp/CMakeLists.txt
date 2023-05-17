cmake_minimum_required(VERSION 3.12)
project(midl_compiler)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES midl_compiler.cpp)

find_package(yaml-cpp REQUIRED)

add_executable(midl_compiler ${SOURCE_FILES})
target_link_libraries(midl_compiler yaml-cpp)

