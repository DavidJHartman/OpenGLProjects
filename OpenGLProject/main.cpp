#include <iostream>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

using namespace std;

int main( int argc, char** argv )
{

    glfwInit();

    GLFWwindow* window;

    window = glfwCreateWindow( 640, 480, "OpenGL Application", nullptr, nullptr );

    glfwMakeContextCurrent( window );

    gl3wInit();

    while ( !glfwWindowShouldClose( window ) ) {

        glfwSwapBuffers( window );
        glfwPollEvents();

    }

    glfwDestroyWindow( window );

    glfwTerminate();

    return 0;
}
