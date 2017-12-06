#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED
#include <string>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <inputHandler.hpp>

void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );

namespace App {

class OpenGLWindow {
public:
    OpenGLWindow( int resolutionWidth, int resolutionHeight, std::string windowName, bool fullscreen = false, bool windowed = true );

    ~OpenGLWindow();

    void Update() {

        if (IO.pollCloseKey())
            CloseWindow = true;

    }

    bool ShouldClose() { return CloseWindow; }

    void display() { glfwSwapBuffers( window ); }
    bool pollEvents() { glfwPollEvents(); }

private:
    GLFWwindow* window;
    int resolutionWidth, resolutionHeight;
    std::string windowName;
    bool CloseWindow;
    InputHandler IO;

};

}

#endif // APPLICATION_HPP_INCLUDED
