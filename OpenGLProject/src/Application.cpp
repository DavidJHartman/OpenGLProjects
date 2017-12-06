#include <Application.hpp>

App::OpenGLWindow::OpenGLWindow( int resolutionWidth, int resolutionHeight, std::string windowName, bool fullscreen, bool windowed ) :
    resolutionWidth{resolutionWidth}, resolutionHeight{resolutionHeight}, windowName{windowName} {

    glfwInit();

    window = glfwCreateWindow( resolutionWidth, resolutionHeight, windowName.c_str(), (GLFWmonitor*)((int)glfwGetPrimaryMonitor() * fullscreen), nullptr );

    if ( fullscreen && windowed ) {

        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwSetWindowMonitor( window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate );

    }

    glfwMakeContextCurrent( window );
    glfwSetWindowUserPointer( window, &IO );

    glfwSetKeyCallback( window, &key_callback );

    gl3wInit();

    CloseWindow = false;

}

App::OpenGLWindow::~OpenGLWindow() {
    glfwDestroyWindow( window );
    glfwTerminate();
}

void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods ) {

    InputHandler* IO = (InputHandler*)glfwGetWindowUserPointer( window );
    IO->updateKey( key, action );

}
