#ifndef FFP_TUM_PERSON_H
#define FFP_TUM_PERSON_H
#include "HealthState.hpp"
#include <Box.hpp>


class Person {
private:
    HealthState healthState = HealthState::SUSCEPTIBLE;
    std::pair<float, float> position;
    std::pair<float, float> direction;
    Box* box;
public:
    Person(Box* box);

    void updatePosition();

    HealthState getHealthState() const;

    void setHealthState(HealthState healthState);

    const std::pair<float, float> &getPosition() const;

    void setPosition(const std::pair<float, float> &position);

    const std::pair<float, float> &getDirection() const;

    void setDirection(const std::pair<float, float> &direction);

    Box *getBox() const;

    void setBox(Box *box);
};


#endif //FFP_TUM_PERSON_H
