cmake_minimum_required(VERSION 3.16)
project(csv_reader_project LANGUAGES CXX)

# Include FetchContent module
include(FetchContent)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable warnings
add_compile_options(-Wall -Wextra)

# Set optimization flags for Release builds
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native -flto")

# Fetch csv-parser
FetchContent_Declare(
  csv
  GIT_REPOSITORY https://github.com/vincentlaucsb/csv-parser.git
  GIT_SHALLOW TRUE
  GIT_TAG 2.2.1
)
FetchContent_MakeAvailable(csv)

# Add executable
add_executable(csv_reader.o csv_reader.cpp)

# Link csv-parser
target_link_libraries(csv_reader.o PRIVATE csv)
target_include_directories(csv_reader.o PRIVATE ${csv_SOURCE_DIR}/single_include)

