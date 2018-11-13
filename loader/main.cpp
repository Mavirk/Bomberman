#include "game.hpp"

// camera
// glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
// glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
// glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
// float deltaTime = 0.0f;	// time between current frame and last frame
// float lastFrame = 0.0f;

int main(){
    int running = 0;
    Game game;
    running = game.init();
    if (running == 1) 
        game.run();
    // camera/view transformation
    // glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    glfwTerminate();
    return 0;
}