#ifndef FFP_TUM_GUI_H
#define FFP_TUM_GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "Model.hpp"

class GUI {
private:
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* person_tex = nullptr;
    SDL_Texture* infected_tex = nullptr;
    Model model;

    void drawBox(int, int);
    void renderPeople();

public:
    GUI(unsigned int, unsigned int, unsigned int, unsigned int, float, float);
    ~GUI();
    void run();
};


#endif //FFP_TUM_GUI_H
