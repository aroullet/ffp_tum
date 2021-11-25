#ifndef FFP_TUM_PERSON_H
#define FFP_TUM_PERSON_H
#include "HealthState.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

struct Box{
    unsigned int x = 30;
    unsigned int y = 30;
};

class Person {
private:
    static Box* box;
    static double speed;
    static double size;

    HealthState healthState = HealthState::SUSCEPTIBLE;
    std::pair<double, double> direction;
    std::map<Person*, int> nrHitsPPerson;
    SDL_Rect dest;
public:

    Person();

    void updatePosition();

    bool updateHealthState(std::vector<Person*> &infectedPeople);

    void calcDistance(Person other);

    HealthState getHealthState() const;

    void setHealthState(HealthState healthState);

    const std::pair<double, double> &getDirection() const;

    void setDirection(const double &xDirection, const double &yDirection);
};


#endif //FFP_TUM_PERSON_H
