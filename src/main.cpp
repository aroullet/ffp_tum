#include <iostream>
#include <limits>
#include "Model.hpp"
#include "GUI.hpp"
#include "main.hpp"

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

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
    float squareRadius = 100;//nearly direct hits

    // Get user input for all variables to initialize model
    const std::string nPeopleMessage = "Enter total number of people to visualize: ";
    getUserInput(nPeople, nPeopleMessage);
    const std::string nInfectedMessage = "Enter the number of infected people: ";
    getUserInput(nInfected, nInfectedMessage);

    while(nInfected>nPeople){
        std::cout << "Number of infected people must be smaller than total number of "<<nPeople<<"! Please enter valid number: ";
        getUserInput(nInfected, "");
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

void getUserInput(unsigned int& value, const std::string& promptMsg) {
    while (true) {
        std::cout << promptMsg;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();  // reset out of failure mode (also covers over-/underflows)
            clearInputBuffer(); // remove incorrect input
            std::cout << "Invalid value specified.\n";
        } else {
            clearInputBuffer();
            break;
        }
    }
}