cmake_minimum_required(VERSION 3.10)
project(CHNO)

set(CMAKE_CXX_STANDARD 14)

add_executable(CHNO main.cpp include/verifierCertificat.h include/Parcours.h src/Parcours.cpp include/Graph.h src/Graph.cpp include/Link.h src/Link.cpp)
add_executable(genereEtTeste GenereEtTeste.cpp include/Graph.h src/Graph.cpp include/graphReader.h include/verifierCertificat.h include/Link.h src/Link.cpp)