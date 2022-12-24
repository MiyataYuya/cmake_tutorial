cmake_minimum_required(VERSION 3.10)

project(miyata VERSION 1.0)

option(USE_ADDER "A simple library for adding 2 floats." ON)

if(USE_ADDER)
    add_subdirectory(src/Adder)

    # list(APPEND EXTRA_LIBS Adder)
    list(APPEND EXTRA_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/src/Adder)
    list(APPEND EXTRA_LINKS adder)

endif()

add_executable(${PROJECT_NAME} src/main.cpp )

configure_file(miyataconfig.h.in miyataconfig.h)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR}
)

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDES_DIR}
)

# target_link_directories(${PROJECT_NAME} 
#     PRIVATE src/Adder
#     PRIVATE external/glfw/src
# )

# !!add_subdirectory で追加したCMakeLists.txt の変数 adder と glfw を使っている。adder は明らかだけど、glfw は external/glfw/CMakeLists.txt 131行目で追加している、external/glfw/src/CMakeLists.txt の中で宣言されている。
target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)