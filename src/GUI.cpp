#include "GUI.hpp"
#include <iostream>

GUI::GUI(int width_, int height_) : width(width_), height(height_) {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &win, &renderer);
    SDL_RenderClear(renderer);

    renderCircle(10, 20);
}



GUI::~GUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    IMG_Quit();
    SDL_Quit();
}

void GUI::renderCircle(int x, int y) {
    SDL_Surface* circle = IMG_Load("../assets/circle.svg");
    if (circle == nullptr) std::cout << "Error";
    SDL_Texture* circleTexture = SDL_CreateTextureFromSurface(renderer, circle);
    SDL_FreeSurface(circle);

    SDL_Rect dest;
    dest.h = height/2;
    dest.w = width/2;

    dest.x = (width - dest.w)/2;
    dest.y = (height - dest.h)/2;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, circleTexture, NULL, &dest);
    SDL_RenderPresent(renderer);
}


int main() {

    GUI gui(1000, 1000);

    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_Delay(10);
        SDL_PollEvent(&event);
    }

    return 0;
}