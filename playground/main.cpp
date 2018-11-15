#include "game.hpp"

int main(){
    int running = 0;
    Game game;
    std::cout << "Main 1" << std::endl;
    running = game.init();
    std::cout << "Main 2" << std::endl;
    if (running == 1){
        std::cout << "Main 3" << std::endl;
        game.run();
    }
    glfwTerminate();
    return 0;
}