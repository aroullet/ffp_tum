#ifndef FFP_TUM_GUI_HPP
#define FFP_TUM_GUI_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

class GUI {
private:
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;

    int width, height;

public:
    GUI(int, int);
    ~GUI();
    SDL_Window* getWin() const { return win; };
};


#endif //FFP_TUM_GUI_HPP
