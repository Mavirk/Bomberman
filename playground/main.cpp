#include "game.hpp"

int main(){
    int running = 0;
    Game game;
    std::cout << "Works!!!" << std::endl;
    running = game.init();
    std::cout << "Works2!!!" << std::endl;
    if (running == 1)
    {
        std::cout << "Works3!!!" << std::endl;
        game.run();
    }
    glfwTerminate();
    return 0;
}