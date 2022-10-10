cmake_minimum_required(VERSION 3.10)

project(miyata)

add_executable(${PROJECT_NAME} src/main.cpp )

add_subdirectory(src/Adder)

target_include_directories(${PROJECT_NAME} PUBLIC src/Adder)

target_link_directories(${PROJECT_NAME} PRIVATE src/Adder)

target_link_libraries(${PROJECT_NAME} adder)