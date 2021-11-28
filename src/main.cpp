#include <iostream>
#include "Model.hpp"
#include "GUI.hpp"

int main() {

    std::cout << "************************************************************" << std::endl;
    std::cout << "************************************************************" << std::endl;
    std::cout << "**  ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄   ▄▄▄   **" << std::endl;
    std::cout << "**  █       █       █       █  █       █  █ █  █  █▄█  █  **" << std::endl;
    std::cout << "**  █    ▄▄▄█    ▄▄▄█    ▄  █  █▄     ▄█  █ █  █       █  **" << std::endl;
    std::cout << "**  █   █▄▄▄█   █▄▄▄█   █▄█ █    █   █ █  █ █  █       █  **" << std::endl;
    std::cout << "**  █    ▄▄▄█    ▄▄▄█    ▄▄▄█    █   █ █  █▄█  █       █  **" << std::endl;
    std::cout << "**  █   █   █   █   █   █        █   █ █       █ ██▄██ █  **" << std::endl;
    std::cout << "**  █▄▄▄█   █▄▄▄█   █▄▄▄█        █▄▄▄█ █▄▄▄▄▄▄▄█▄█   █▄█  **" << std::endl;
    std::cout << "************************************************************" << std::endl;
    std::cout << "************************************************************" << std::endl;


    std::cout << "Welcome to our pandemic simulator!" << std::endl;

    unsigned int nPeople = 0;
    unsigned int width = 1000;
    unsigned int height = 1000;
    float spreadProb =0;
    float radius = 0;
    // Get user input for all variables to initialize model
    std::cout << "Enter the number of people to visualize: ";
    std::cin >> nPeople;

    GUI gui(nPeople, width, height, spreadProb, radius);
    gui.run();

    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(10);
        SDL_PollEvent(&event);
    }

    return 0;
}