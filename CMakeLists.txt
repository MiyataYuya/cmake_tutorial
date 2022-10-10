cmake_minimum_required(VERSION 3.10)

project(miyata VERSION 1.0)

add_executable(${PROJECT_NAME} src/main.cpp )

add_subdirectory(src/Adder)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC src/Adder 
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE src/Adder
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} adder glfw)