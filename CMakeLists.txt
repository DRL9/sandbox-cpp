cmake_minimum_required(VERSION 3.21)
project(sandbox-cpp VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(sandbox-cpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
