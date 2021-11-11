#ifndef FFP_TUM_PERSON_H
#define FFP_TUM_PERSON_H
#include "HealthState.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <Box.hpp>


class Person {
private:
    HealthState healthState = HealthState::SUSCEPTIBLE;
    std::pair<double, double> position;
    std::pair<double, double> direction;
    Box* box;
public:
    Person(Box* box);

    void updatePosition(std::pair<double, double> pos);

    double calcDistance(Person other);

    HealthState getHealthState() const;

    void setHealthState(HealthState healthState);

    const std::pair<double, double> &getPosition() const;

    void setPosition(double x, double y);

    const std::pair<double, double> &getDirection() const;

    void setDirection(double x, double y);

    Box *getBox() const;

    void setBox(Box *box);
};


#endif //FFP_TUM_PERSON_H
