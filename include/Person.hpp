#ifndef FFP_TUM_PERSON_H
#define FFP_TUM_PERSON_H
#include "HealthState.hpp"
#include <iostream>
#include "Box.hpp"
#include "Virus.hpp"
#include <unordered_map>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

class Person {
public:
    /**
     * Static Attributes:
     * @param box - Given Box for the people wandering around
     * @param virus - The virus with the attributes of radius and probability of infection.
     * @param speed - The speed people move.
     * @param size - Double the size of a person in the gui.
     */
    static Box* p_box;
    static Virus* s_virus;
    static double s_speed;
    static double s_size;

    /**
     * Local, private, non-static Attributes:
     * @param healthState - health state of a person with a default value of not-infected
     * @param direction - the direction of this persons movements
     * @param nrHitsPPerson -
     * @param dest - the object for the
     */
    HealthState healthState;
    std::pair<double, double> direction;
    std::unordered_map<Person*, unsigned int> nrHitsPPerson;
    SDL_Rect dest;
    /**
     * This function should be private since we do not need to calculate the distance
     * outside of this class
     *
     * @param other - another Person to which we calculate the euclidean distance
     * @return - the distance
     */
    double calcDistance(Person *other);
public:

    /**
     * It is assumed that the static values are already initialized otherwise an error s thrown.
     * The SDLRect is set to a position randomly in the given box with the given size of the
     * person's picture. And a randomized normalized direction vector is set.
     */
    explicit Person(HealthState state=HealthState::SUSCEPTIBLE);

    /**
     * This updates the position of this Person for one timestep. according to the given direction.
     * It also respects the boundaries of the box an redirects the person in a sense that the position
     * is still in the box although the direction might at first says differently and the direction
     * is set as it bounces of the wall of the box.
     */
    void updatePosition();

    /**
     * This iterates over the given set of infected people. Compares their distance
     * with this given Person and increases the map value if a specific person from this
     * set is too close according to the virus.
     *
     * @param infectedPeople - set of people which are currently infected
     * @return - true if this Person changes its healthState
     */
    bool updateHealthState(std::vector<Person*> &infectedPeople);

    /**
     * People out of range should be deleted or set to zero.
     * This function just deletes(sets to zero) the person in the nrHitsPPerson-Map.
     *
     * @param people - a vector of person-pointers
     */
    void deleteInfectedFromMap(std::vector<Person*> &people);

    /**
     * A person out of range should be deleted or set to zero.
     * This function just deletes(sets to zero) the person in the nrHitsPPerson-Map.
     *
     * @param person
     */
    void deleteInfectedFromMap(Person &person);

    void setHealthState(HealthState healthState);

    SDL_Rect &getDest();

    HealthState getHealthState() const;

    std::pair<double, double> getPosition();
};


#endif //FFP_TUM_PERSON_H
