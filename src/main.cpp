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
    unsigned int nInfected = 0;
    unsigned int width = 1000;
    unsigned int height = 1000;
    float spreadProb =0.5;//irrelevant so far
    float squareRadius = 100;//nearly direct hits
    // Get user input for all variables to initialize model
    std::cout << "Enter total number of people to visualize: ";
    std::cin >> nPeople;
    std::cout << "Enter the number of infected people: ";
    std::cin >> nInfected;
    while(nInfected>nPeople){
        std::cout << "Number of infected people must be smaller than total number of "<<nPeople<<"! Please enter valid number: ";
        std::cin >> nInfected;
    }

    GUI gui(nPeople, nInfected, width, height, spreadProb, squareRadius);
    gui.run();

    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(25);
        SDL_PollEvent(&event);
    }

    return 0;
}