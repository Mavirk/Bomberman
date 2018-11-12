#include <iostream>
#include "game.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    if (window)
        glViewport(0, 0, width, height);
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
        // INPUT
        handleInput(window);
        
        // rendering commands here
        // ...
        
        // check events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
    return;
}

void Game::handleInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
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
    return 1;
}
