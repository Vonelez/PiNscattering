cmake_minimum_required(VERSION 3.13)
project(PiN)

set(CMAKE_CXX_STANDARD 14)

add_executable(PiN main.cpp src/Dat.cpp include/Dat.h src/Legendre.cpp include/Legendre.h src/Momentum.cpp include/Momentum.h src/Amplitudes.cpp include/Amplitudes.h src/Argand.cpp include/Argand.h src/CrossSection.cpp include/CrossSection.h)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED COMPONENTS RIO Net)

include(${ROOT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)