#include "game.hpp"

int main(){
    int running = 0;
    Game game;
    running = game.init();
    if (running == 1) 
        game.run();
    glfwTerminate();
    return 0;
}