cmake_minimum_required(VERSION 3.12)
project(midl_compiler)

find_package(yaml-cpp REQUIRED)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES midl_compiler.cc)

add_executable(midl_compiler ${SOURCE_FILES})
target_link_libraries(midl_compiler yaml-cpp)

##############################################

enable_testing()
find_package(GTest REQUIRED)

set(TEST_SOURCE_FILES midl_compiler_tests.cc)

add_executable(midl_compiler_tests ${TEST_SOURCE_FILES})
target_link_libraries(midl_compiler_tests yaml-cpp GTest::gtest GTest::gtest_main)


add_test(NAME midl_compiler_tests COMMAND midl_compiler_tests)

