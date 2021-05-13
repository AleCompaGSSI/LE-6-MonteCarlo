cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(MC_EX)

set(CMAKE_CXX_STANDARD 11)


list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED COMPONENTS RIO Net)
include(${ROOT_USE_FILE})
include_directories(${ROOT_INCLUDE_DIR})

include_directories("${CMAKE_SOURCE_DIR}")

include_directories (include)

add_executable(ex1a src/ex1/ex1a.cc)

target_link_libraries(ex1a "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex1b src/ex1/ex1b.cc)

target_link_libraries(ex1b "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

