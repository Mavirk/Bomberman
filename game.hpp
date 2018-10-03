#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
class Game {
    public:
        GLFWwindow* window;
        bool    running;
        Game();
        ~Game();
        int     init();
        void    run();
        void    handleInput(GLFWwindow* window);

};

#endif
