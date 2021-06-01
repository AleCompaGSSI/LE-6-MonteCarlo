cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(MC_EX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O3")


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

add_executable(ex1c src/ex1/ex1c.cc)

target_link_libraries(ex1c "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex2 src/ex2/ex2.cc)

target_link_libraries(ex2 "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex3a src/ex3/ex3a.cc)

target_link_libraries(ex3a "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex3b src/ex3/ex3b.cc)

target_link_libraries(ex3b "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex3c src/ex3/ex3c.cc)

target_link_libraries(ex3c "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex4a src/ex4/ex4a.cc)

target_link_libraries(ex4a "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex4b src/ex4/ex4b.cc)

target_link_libraries(ex4b "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex5a src/ex5/ex5a.cc)

target_link_libraries(ex5a "${ROOT_LIBRARIES}" "-Wl -lSpectrum")

add_executable(ex6 src/ex6/ex6.cc)

target_link_libraries(ex6 "${ROOT_LIBRARIES}" "-Wl -lSpectrum")
