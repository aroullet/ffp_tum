#include "GUI.hpp"


int main() {

    bool open = true;

    SDL_Window* win = SDL_CreateWindow("Pandemic simulation",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 700, 0);
    while (open) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                open = false;
        }
    }

    return 0;
}