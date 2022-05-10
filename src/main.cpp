#include <iostream>
#include "Model.hpp"
#include "GUI.hpp"
#include "InputHandler.hpp"


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

    unsigned nPeople = 0;
    unsigned nInfected = 0;
    unsigned width = 500;
    unsigned height = 500;
    float spreadProb = 0.01;
    float radius = 10;//nearly direct hits

    // Get user input for all variables to initialize model
    const std::string nPeopleMsg = "Enter total number of people to visualize: ";
    getUserInput<unsigned int>(nPeople, nPeopleMsg);
    const std::string nInfectedMsg = "Enter the number of infected people: ";
    getUserInput<unsigned int>(nInfected, nInfectedMsg);

    while(nInfected>nPeople){
        std::cout << "Number of infected people must be smaller than total number of "<<nPeople<<"! Please enter valid number: ";
        getUserInput<unsigned>(nInfected, "");
    }

    const std::string radiusMsg = "Please specify the infection radius (in pixels): ";
    getUserInput<float>(radius, radiusMsg);
    float squareRadius = radius * radius;

    GUI gui(nPeople, nInfected, width, height, spreadProb, squareRadius);
    gui.run();

    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(25);
        SDL_PollEvent(&event);
    }

    return 0;
}