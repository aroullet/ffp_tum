#ifndef FFP_TUM_GUI_H
#define FFP_TUM_GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

class GUI {
private:
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;
    int width, height;

    void drawBox(int, int);
    void renderCircle(int, int);

public:
    GUI(int, int);
    ~GUI();
    SDL_Window* getWin() const { return win; };
};


#endif //FFP_TUM_GUI_H
