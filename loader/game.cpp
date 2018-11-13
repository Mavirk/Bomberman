#include <iostream>
#include "game.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    if (window)
        glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    int temp = scancode;
    temp = mods;
    if (action == GLFW_PRESS){
        switch(key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                std::cout << "EXIT EXIT EXIT" << std::endl;
                break;
            case GLFW_KEY_UP:
                std::cout << "UP UP UP" << std::endl;
                break;
            case GLFW_KEY_DOWN:
                std::cout << "DOWN DOWN DOWN" << std::endl;
                break;
            case GLFW_KEY_LEFT:
                std::cout << "LEFT LEFT LEFT" << std::endl;
                break;
            case GLFW_KEY_RIGHT:
                std::cout << "RIGHT RIGHT RIGHT" << std::endl;
                break;
            case GLFW_KEY_SPACE:
                std::cout << "SPACE SPACE SPACE" << std::endl;
                break;
        }            
    }
}

Game::~Game(){
    return;
}

Game::Game(){
    return;
}

void    Game::run(){
    
    while(!glfwWindowShouldClose(window)){
        // Clear Screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // rendering commands here
        // ...
        // check events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
    return;
}


int    Game::init(){
    // Init glfw with version number 
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // Create the window instance
    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    // Check if window is created
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    return 1;
}
