cmake_minimum_required(VERSION 3.15)
project(LexicalAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(LexicalAnalysis main.cpp DFA.cpp DFA.h Scanner.cpp Scanner.h)