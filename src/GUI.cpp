#include "GUI.hpp"

GUI::GUI(int width_, int height_) : width(width_), height(height_) {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &win, &renderer);
    SDL_RenderClear(renderer);
}



GUI::~GUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
}


int main() {

    GUI gui(1000, 700);
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