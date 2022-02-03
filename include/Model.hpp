#ifndef FFP_TUM_MODEL_H
#define FFP_TUM_MODEL_H

#include <vector>
#include <memory>
#include "Box.hpp"
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

class GUI; // Need forward declaration to avoid circular dependency

class Model {
private:
    Virus virus;
    std::vector<std::shared_ptr<Person>> people;
    std::vector<std::shared_ptr<Person>> infected;
    std::vector<std::shared_ptr<Person>> recovered;
    Box box;

    /**
     * Updates position of everyone regardless of their HealthState.
     */
    static void movePeople(const std::vector<std::shared_ptr<Person>>&);

    /**
     * Runs the infection checks for all susceptible people and checks recovery
     * for each infected person for one time step.
     */
    void updateState();

public:
    Model(unsigned N, unsigned iN, unsigned width, unsigned height, float prob, float radius);
    friend class GUI;
};


#endif //FFP_TUM_MODEL_H
