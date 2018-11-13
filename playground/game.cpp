#include "game.hpp"

void
framebuffer_size_callback(GLFWwindow* window, int width, int height){
    if (window)
        glViewport(0, 0, width, height);
}

// Is called whenever a key is pressed/released via GLFW
void
KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    int temp = scancode;
    temp = mods;
    if (action == GLFW_PRESS){
        switch(key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                std::cout << "EXIT EXIT EXIT" << std::endl;
                break;
            case GLFW_KEY_W:
                camera.DoMovement(1, deltaTime);
                std::cout << "UP UP UP" << std::endl;
                break;
            case GLFW_KEY_S:
                camera.DoMovement(2, deltaTime);
                std::cout << "DOWN DOWN DOWN" << std::endl;
                break;
            case GLFW_KEY_A:
                camera.DoMovement(3, deltaTime);
                std::cout << "LEFT LEFT LEFT" << std::endl;
                break;
            case GLFW_KEY_D:
                camera.DoMovement(4, deltaTime);
                std::cout << "RIGHT RIGHT RIGHT" << std::endl;
                break;
            case GLFW_KEY_SPACE:
                std::cout << "SPACE SPACE SPACE" << std::endl;
                break;
        }            
    }
}

void
ScrollCallback(GLFWwindow *window, double xOffset, double yOffset){
    // UNUSED
    GLFWwindow *temp = 0;
    temp = window;
    double temp1 = 0;
    temp1 = xOffset;
    // UNUSED
    camera.ProcessMouseScroll(yOffset);
}

void
MouseCallback( GLFWwindow *window, double xPos, double yPos ) {
    // UNUSED
    GLFWwindow *temp = 0;
    temp = window;
    // UNUSED
    if ( firstMouse )
    {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }
    
    GLfloat xOffset = xPos - lastX;
    GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left
    
    lastX = xPos;
    lastY = yPos;
    
    camera.ProcessMouseMovement( xOffset, yOffset, true);
}

Game::~Game(){
    return;
}

Game::Game(){
    return;
}
// Moves/alters the camera positions based on user input

void
Game::run(){
    while(!glfwWindowShouldClose(window)){
        //get frames
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
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

void
Game::handleInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int
Game::init(){
    // Init glfw with version number 
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // Create the window instance
    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
    // Check if window is created
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //set mouse cursor to be fix to the window
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //set callbacks
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, MouseCallback);
    glfwSetScrollCallback(window, ScrollCallback);
    camera = Camera();
    return 1;
}
