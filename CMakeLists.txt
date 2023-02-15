cmake_minimum_required(VERSION 3.24)
project(WordleCloneCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordleCloneCPP main.cpp src/game.cpp src/game.h src/wordList.cpp src/wordList.h)
