#ifndef FFP_TUM_PERSON_H
#define FFP_TUM_PERSON_H
#include "HealthState.hpp"


class Person {
private:
    HealthState healthState = HealthState::SUSCEPTIBLE;
};


#endif //FFP_TUM_PERSON_H
