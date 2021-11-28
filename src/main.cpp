#include <iostream>
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
    GUI gui(1000, 1000);

    int nPeople;
    std::cout << "Enter the number of people to visualize: ";
    std::cin >> nPeople;

    gui.run(nPeople);

    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(10);
        SDL_PollEvent(&event);
    }

    return 0;
}
