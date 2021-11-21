#ifndef FFP_TUM_GUI_HPP
#define FFP_TUM_GUI_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

class GUI {
private:
    SDL_Window* win;
    void setUp();

public:
    GUI();
    ~GUI();
    SDL_Window* getWin() const { return win; };
};


#endif //FFP_TUM_GUI_HPP
