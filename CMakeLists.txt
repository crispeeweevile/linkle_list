cmake_minimum_required(VERSION 3.26.0)
project(LinklList VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include/internal)
add_library(LinklList ${CMAKE_SOURCE_DIR}/src/LinklList.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
