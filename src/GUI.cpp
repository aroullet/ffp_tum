#include "GUI.hpp"
#include <iostream>
#include "Person.hpp"

GUI::GUI(int width_, int height_) : width(width_), height(height_) {
    //SDL_Init(SDL_INIT_VIDEO);
    //SDL_CreateWindowAndRenderer(width, height, 0, &win, &renderer);
    //SDL_RenderClear(renderer);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    win = SDL_CreateWindow("SIR-MODEL", // creates a window
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       width, height, 0);

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images
    renderer = SDL_CreateRenderer(win, -1, render_flags);

    //renderCircle(10, 20);
    //drawBox(900, 900);
    //SDL_RenderPresent(renderer);
}


GUI::~GUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    IMG_Quit();
    SDL_Quit();
}

void GUI::drawBox(int w, int h) {
    SDL_Rect box;
    box.x = 50;
    box.y = 50;
    box.w = w;
    box.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &box);
}
/**
 * This should be probably partially in the model class.
 * it creates an vector of person and just calles the update function
 * of a person to get their new position.
 * It might be helpful.
 *
 * you should probebly alway check if the quit button is pressed.
 */
void GUI::run(int nPeople) {
    SDL_Surface* person_sur = IMG_Load("../assets/circle.svg");
    SDL_Texture* person_tex = SDL_CreateTextureFromSurface(renderer, person_sur);
    SDL_FreeSurface(person_sur);
    Person::s_size = 30;
    Person::p_box = new Box{1000, 1000};
    Person::s_speed = 10;
    SDL_RenderClear(renderer);
    std::vector<Person> v(nPeople);
    for (auto i = 0; i< nPeople; i++){
        v.push_back(Person());
        SDL_RenderCopy(renderer, person_tex, NULL, &(v[i].dest));
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(50);
    for(int i = 0; i< 400; i++){
        SDL_RenderClear(renderer);
        for(int j = 0; j<nPeople; j++){
            v[j].updatePosition();
            SDL_RenderCopy(renderer, person_tex, NULL, &(v[j].dest));
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }
}