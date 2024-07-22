cmake_minimum_required(VERSION 3.28)
project(Grade_Predictor)

set(CMAKE_CXX_STANDARD 17)


# Add vcpkg integration
set(CMAKE_TOOLCHAIN_FILE "C:/Users/thehe/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(nlohmann_json CONFIG REQUIRED)

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

target_link_libraries(Grade_Predictor PRIVATE nlohmann_json::nlohmann_json)