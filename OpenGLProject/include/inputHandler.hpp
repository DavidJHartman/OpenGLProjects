#ifndef INPUTHANDLER_HPP_INCLUDED
#define INPUTHANDLER_HPP_INCLUDED
#include <iostream>
#include <GLFW/glfw3.h>

class InputHandler {
public:
    bool isKeyPressed( int key) { return keys[key];}
    void updateKey( int key, int state ) { keys[key] = state; }

    bool pollCloseKey() {
        return keys[closeKey];
    }

    InputHandler() {
        for (int i = 0; i < 1024 / 4; i++) {
            keys[i + 0] = false;
            keys[i + 1] = false;
            keys[i + 2] = false;
            keys[i + 3] = false;
        }
    }

private:
    bool keys[1024];

    int closeKey = GLFW_KEY_ESCAPE;

};

#endif // INPUTHANDLER_HPP_INCLUDED
