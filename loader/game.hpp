#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
class Game {
    public:
        GLFWwindow* window;
        bool    running;
        char    **map;
        Game();
        ~Game();
        int     init();
        void    run();

};

#endif
