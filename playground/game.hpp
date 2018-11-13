#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "./camera.hpp"

// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void    KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
// void    ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
// void    MouseCallback(GLFWwindow *window, double xPos, double yPos);
//screen
int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
GLfloat lastX = 800 / 2.0f;
GLfloat lastY = 600 / 2.0f;
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
bool keys[1024];
bool firstMouse = true;
Camera camera;

class Game {
    public:
        GLFWwindow* window;
        bool    running;
        Game();
        ~Game();
        int     init();
        void    run();
        void    handleInput(GLFWwindow* window);
        // static Camera::camera; //= new Camera();
};

#endif
