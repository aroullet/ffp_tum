#include "Person.hpp"

Person::Person(Box* Box) {
    this.Box = Box;
    setPosition() temp = 1.0 * rand()*(numVertices)/RAND_MAX;//nachbar grad
};

void Person::updatePosition() {

}

HealthState Person::getHealthState() const {
    return healthState;
}

void Person::setHealthState(HealthState healthState) {
    Person::healthState = healthState;
}

const std::pair<float, float> &Person::getPosition() const {
    return position;
}

void Person::setPosition(const std::pair<float, float> &position) {
    Person::position = position;
}

const std::pair<float, float> &Person::getDirection() const {
    return direction;
}

void Person::setDirection(const std::pair<float, float> &direction) {
    Person::direction = direction;
}

Box *Person::getBox() const {
    return box;
}

void Person::setBox(Box *box) {
    Person::box = box;
}
