cmake_minimum_required(VERSION 3.28)
project(Grade_Predictor)

# For mac
set(CMAKE_TOOLCHAIN_FILE "/Users/harrisonbaker/vcpkg/scripts/buildsystems/vcpkg.cmake")

# For windows
# set(CMAKE_TOOLCHAIN_FILE "C:/Users/thehe/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 17)

# Find the nlohmann_json package
find_package(nlohmann_json CONFIG REQUIRED)

# Add executable target
add_executable(Grade_Predictor
        main.cpp
        src/Assignment.cpp
        include/Assignment.h
        include/GradePrediction.h
        src/GradePrediction.cpp
        include/Category.h
        src/Category.cpp
        include/FileManager.h
        src/FileManager.cpp
        include/ConsoleManager.h
        src/ConsoleManager.cpp
)

# Link the nlohmann_json library to the executable
target_link_libraries(Grade_Predictor PRIVATE nlohmann_json::nlohmann_json)
