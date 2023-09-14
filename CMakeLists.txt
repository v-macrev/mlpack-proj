cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Find JSON for Modern C++
find_package(nlohmann_json 3.10.2 REQUIRED)
include_directories(${nlohmann_json_INCLUDE_DIRS})

# Add your source files
add_executable(your_executable src/main.cpp)

# Link your executable with the JSON for Modern C++ library
target_link_libraries(your_executable PRIVATE nlohmann_json::nlohmann_json)
