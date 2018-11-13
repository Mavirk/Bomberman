#include "game.hpp"
// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Game::Game(){
    return;
}

Game::~Game(){
    return;
}


// Moves/alters the camera positions based on user input

void
Game::run(){
    while(!glfwWindowShouldClose(window)){
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // render
        // ------
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // don't forget to enable shader before setting uniforms
        ourShader.use();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.GetZoom()), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        // render the loaded model
        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
        ourShader.setMat4("model", model);
        ourModel.Draw(ourShader);
        
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return;
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


    // Check if window is created
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //set callbacks
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetCursorPosCallback(window, MouseCallback);
    glfwSetScrollCallback(window, ScrollCallback);

    //set mouse cursor to be fix to the window
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);

    Shader  ourShader("modelLoading.vs", "modelLoading.fs");
    Model   ourModel("resources/objects/nanosuit/nanosuit.obj");
    return 1;
}

void
FramebufferSizeCallback(GLFWwindow* window, int width, int height){
    if (window)
        glViewport(0, 0, width, height);
}

// Is called whenever a key is pressed/released via GLFW
void
KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    int temp = scancode;
    temp = mods;
    Camera camera;
    GLfloat deltaTime = 0.0f;
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
    Camera camera;
    std::cout << "Scroll" << yOffset << std::endl;
    camera.ProcessMouseScroll(yOffset);
}

void
MouseCallback( GLFWwindow *window, double xPos, double yPos ) {
    // UNUSED
    GLFWwindow *temp = 0;
    temp = window;
    bool firstMouse = true;
    GLfloat lastX = 800 / 2.0f;
    GLfloat lastY = 600 / 2.0f;
    // UNUSED
    Camera camera;
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
    
    std::cout << "X : " << xPos << "Y : " << yPos  << std::endl;
    camera.ProcessMouseMovement( xOffset, yOffset, true);
}
