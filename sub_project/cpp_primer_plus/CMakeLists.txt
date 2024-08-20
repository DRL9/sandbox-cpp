cmake_minimum_required(VERSION 3.21)
project(cpp_primer_v6 VERSION 0.1.0 LANGUAGES CXX)


include(CTest)
enable_testing()

add_executable(c03_type src/c03_type.cpp)
add_executable(c04_compound src/c04_compound.cpp)
add_executable(c05_loop src/c05_loop.cpp)
add_executable(c05_ex_10 src/c05_ex_10.cpp)
add_executable(c06_control src/c06_control.cpp)
add_executable(c06_ex_8 src/c06_ex_8.cpp)
add_executable(c07_function src/c07_function.cpp)
add_executable(c07_ex_10 src/c07_ex_10.cpp)
add_executable(c08_fn src/c08_fn.cpp)
add_executable(c09_ns src/c09_main.cpp src/c09_coord.cpp src/c09_using_ns.cpp)
add_executable(c10_main src/c10_main.cpp src/c10_stock.cpp)
add_executable(c10_main_stack src/c10_main_stack.cpp src/c10_stack.cpp)
add_executable(c11_main src/c11_main.cpp src/c11_time.cpp)
add_executable(c11_main_vector src/c11_vector_main.cpp src/c11_vector.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_COMPILE "g++")
set(CMAKE_CXX_FLAGS " -Wall -std=c++11")

include(CPack)
