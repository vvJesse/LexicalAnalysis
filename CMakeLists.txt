cmake_minimum_required(VERSION 3.15)
project(LexicalAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(LexicalAnalysis main.cpp NFA.cpp NFA.h Scanner.cpp Scanner.h)