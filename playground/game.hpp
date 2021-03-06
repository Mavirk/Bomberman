#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "camera.hpp"
#include "model.hpp"
#include "shader.hpp"
#include "mesh.hpp"

void    FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void    KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void    ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
void    MouseCallback(GLFWwindow *window, double xPos, double yPos);

class Game {
    public:
        Game();
        ~Game();
        GLFWwindow* window;
        bool        running;
        Model       ourModel;
        Shader      ourShader;  
        Camera      camera;

        
        int     init();
        void    run();
};

#endif
