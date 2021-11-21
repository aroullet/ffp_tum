#include "GUI.hpp"

GUI::GUI() { setUp(); }

GUI::~GUI() {
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void GUI::setUp() {
    win = SDL_CreateWindow("Pandemic simulation",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           1000, 700, 0);
}


int main() {

    GUI gui{};
    bool open = true;
    while (open) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyWindow(gui.getWin());
                SDL_Quit();
                open = false;
            }
        }
    }

    return 0;
}