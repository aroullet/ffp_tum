#include <iostream>
#include <limits>
#include "Model.hpp"
#include "GUI.hpp"
#include "main.hpp"


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
    unsigned int width = 500;
    unsigned int height = 500;
    float spreadProb =0.01;//irrelevant so far
    float radius = 10;//nearly direct hits

    // Get user input for all variables to initialize model
    const std::string nPeopleMsg = "Enter total number of people to visualize: ";
    getUserInput<unsigned int>(nPeople, nPeopleMsg);
    const std::string nInfectedMsg = "Enter the number of infected people: ";
    getUserInput<unsigned int>(nInfected, nInfectedMsg);

    while(nInfected>nPeople){
        std::cout << "Number of infected people must be smaller than total number of "<<nPeople<<"! Please enter valid number: ";
        getUserInput<unsigned int>(nInfected, "");
    }

    const std::string radiusMsg = "Please specify the infection radius (in pixels): ";
    getUserInput<float>(radius, radiusMsg);
    float squareRadius = pow(radius, 2);

    GUI gui(nPeople, nInfected, width, height, spreadProb, squareRadius);
    gui.run();

    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(25);
        SDL_PollEvent(&event);
    }

    return 0;
}