#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "camera.hpp"

void    framebuffer_size_callback(GLFWwindow* window, int width, int height);
void    KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void    ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
void    MouseCallback(GLFWwindow *window, double xPos, double yPos);

class Game {
    public:
        GLFWwindow* window;
        bool    running;
        Game();
        ~Game();
        Camera camera;
        int     init();
        void    run();
        void    handleInput(GLFWwindow* window);
};

#endif
