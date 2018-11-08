cmake_minimum_required(VERSION 3.10)
project(CHNO)

set(CMAKE_CXX_STANDARD 14)

add_executable(CHNO main.cpp src/verifierCertificat.cpp src/Parcours.h src/Parcours.cpp src/Graph.h src/Graph.cpp src/Link.h src/Link.cpp)