#include "GUI.hpp"
#include <iostream>
#include "Person.hpp"

GUI::GUI(unsigned int N, unsigned int iN,unsigned int width, unsigned int height, float prob, float radius)
    : model{N,iN, width, height, prob, radius} {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "error initializing SDL: %s\n" << SDL_GetError();
    }
    win = SDL_CreateWindow("SIR-MODEL", // creates a windows
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           1000, 600, 0);

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images
    renderer = SDL_CreateRenderer(win, -1, render_flags);

    // Do it once in the constructor to move it out of method
    SDL_Surface* person_sur = IMG_Load("../assets/susceptible.svg");
    person_tex = SDL_CreateTextureFromSurface(renderer, person_sur);
    SDL_FreeSurface(person_sur);

    SDL_Surface* infected_sur = IMG_Load("../assets/infected.svg");
    infected_tex = SDL_CreateTextureFromSurface(renderer, infected_sur);
    SDL_FreeSurface(infected_sur);

    SDL_Surface* recovered_sur = IMG_Load("../assets/recovered.svg");
    recovered_tex = SDL_CreateTextureFromSurface(renderer, recovered_sur);
    SDL_FreeSurface(recovered_sur);
}


GUI::~GUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(person_tex);
    SDL_DestroyTexture(infected_tex);
    SDL_DestroyTexture(recovered_tex);


    IMG_Quit();
    SDL_Quit();
}

void GUI::drawBox(int w, int h) {
    SDL_Rect box;
    box.x = 50;
    box.y = 50;
    box.w = w;
    box.h = h;
    box_rect = &box;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, box_rect);
}

void GUI::renderPeople() {

    SDL_RenderClear(renderer);
    for (auto& person : model.people)
        SDL_RenderCopy(renderer, person_tex, nullptr, &(person->dest));

    for (auto&person : model.infected)
        SDL_RenderCopy(renderer, infected_tex, nullptr, &(person->dest));

    for (auto &person: model.recovered)
        SDL_RenderCopy(renderer, recovered_tex, nullptr, &(person->dest));
    SDL_RenderPresent(renderer);
}

void GUI::run() {

    renderPeople();
    SDL_Event event;
    while(event.type != SDL_QUIT) {
        SDL_PollEvent(&event);
        model.updateState();
        renderPeople();
        SDL_Delay(30);
    }
    std::cout << "Simulation over!" << std::endl;
}