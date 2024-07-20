cmake_minimum_required(VERSION 3.28)
project(Grade_Predictor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Grade_Predictor main.cpp
        src/Assignment.cpp
        include/Assignment.h
        include/GradePrediction.h
        src/GradePrediction.cpp
        include/Category.h
        src/Category.cpp
        include/FileManager.h
        src/FileManager.cpp
        include/ConsoleManager.h
        src/ConsoleManager.cpp)
