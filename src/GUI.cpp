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
    renderPerson();
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

void GUI::renderCircle(int x, int y) {
    SDL_Surface* circle = IMG_Load("../assets/circle.svg");
    SDL_Texture* circleTexture = SDL_CreateTextureFromSurface(renderer, circle);
    SDL_FreeSurface(circle);

    SDL_Rect dest;
    dest.h = height/2;
    dest.w = width/2;
    dest.h = 30;
    dest.w = 30;

    dest.x = (width - dest.w)/2;
    dest.y = (height - dest.h)/2;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, circleTexture, NULL, &dest);
}

/**
 * This should be probably partially in the model class.
 * it creates an vector of person and just calles the update function
 * of a person to get their new position.
 * It might be helpful.
 *
 * you should probebly alway check if the quit button is pressed.
 */
void GUI::renderPerson() {
    std::cout << "Please enter the number of Persons to be visualized: ";
    SDL_Surface* person_sur = IMG_Load("../assets/circle.svg");
    SDL_Texture* person_tex = SDL_CreateTextureFromSurface(renderer, person_sur);
    SDL_FreeSurface(person_sur);
    Person::size = 30;
    Person::box = new Box{1000, 1000};
    Person::speed = 10;
    int nrpeople;
    std::cin>> nrpeople;
    SDL_RenderClear(renderer);
    std::vector<Person> v;
    for (auto i = 0; i< nrpeople; i++){
        v.push_back(Person());
        SDL_RenderCopy(renderer, person_tex, NULL, &(v[i].dest));
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    for(int i = 0; i< 400; i++){
        SDL_RenderClear(renderer);
        for(int j = 0; j<nrpeople; j++){
            v[j].updatePosition();
            SDL_RenderCopy(renderer, person_tex, NULL, &(v[j].dest));
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
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