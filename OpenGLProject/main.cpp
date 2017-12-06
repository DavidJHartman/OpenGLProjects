#include <iostream>
#include <Application.hpp>

using namespace std;

int main( int argc, char** argv )
{

    App::OpenGLWindow window( 800, 600, "OpenGL Project" );

    while ( !window.ShouldClose() ) {

        window.Update();
        window.display();
        window.pollEvents();

    }

    return 0;
}
