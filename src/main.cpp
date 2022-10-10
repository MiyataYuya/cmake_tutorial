#include <iostream>
#include "adder.h"
#include <GLFW/glfw3.h>

int main()
{
    float a(4.6f), b(12.5f);

    std::cout << "Hello, world!!\n";

    std::cout << add(a, b) << std::endl;




    GLFWwindow *window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    while( !glfwWindowShouldClose(window) )
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Terminate GLFW
    glfwTerminate();
}