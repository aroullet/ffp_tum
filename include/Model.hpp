#ifndef FFP_TUM_MODEL_H
#define FFP_TUM_MODEL_H

#include <vector>
#include "Box.hpp"
#include "Virus.hpp"
#include "Person.hpp"

/*
 * Explanation of the model's dynamics:
 * Beta is the average of number of contacts per person per unit of time
 * Gamma is the transition rate from infectious to recovered
 * No deaths in simple model
 *
 * Beta in our case is proportional to the box size and the infection radius
 *
 * dS/dt = -Beta*I*S/N,
 * dI/dt = B*I*S/N - gamma*I
 * dR/dt = gamma*I
 */

class Model {
private:
    unsigned int N;
    Box box;
    Virus virus;
    std::vector<Person> people;
    std::vector<Person> recovered;

    void setUp();
    void updateState();

public:
    Model(unsigned int N, unsigned int sideLength, float prob, float radius) { setUp() };
};


#endif //FFP_TUM_MODEL_H
