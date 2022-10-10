cmake_minimum_required(VERSION 3.10)

project(miyata VERSION 1.0)

configure_file(miyataconfig.h.in miyataconfig.h)

add_executable(${PROJECT_NAME} src/main.cpp )

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR}
)

add_subdirectory(src/Adder)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC src/Adder 
    PUBLIC external/glfw/include
)

# target_link_directories(${PROJECT_NAME} 
#     PRIVATE src/Adder
#     PRIVATE external/glfw/src
# )

# !!add_subdirectory で追加したCMakeLists.txt の変数 adder と glfw を使っている。adder は明らかだけど、glfw は external/glfw/CMakeLists.txt 131行目で追加している、external/glfw/src/CMakeLists.txt の中で宣言されている。
target_link_libraries(${PROJECT_NAME} adder glfw)