#include "Person.hpp"

Person::Person(Box* box) {
    this->box = box;
    double xCoord= (1.0 * rand()*box->getWidth())/RAND_MAX;
    double yCoord= (1.0 * rand()*box->getHeight())/RAND_MAX;
    this->setPosition(xCoord, yCoord);
    xCoord= (0.5 * (rand()-RAND_MAX))/RAND_MAX;
    yCoord= (0.5 * (rand()-RAND_MAX))/RAND_MAX;
    double length = sqrt(xCoord*xCoord + yCoord * yCoord);
    this->setDirection(xCoord/length, yCoord/length);
};

void Person::updatePosition(std::pair<double, double> pos) {
    this->position = pos;
}

double Person::calcDistance(Person other){
    auto otherPos = other.getPosition();
    double x = otherPos.first - position.first;
    double y = otherPos.second - position.second;
    return sqrt(x*x + y*y);
}

HealthState Person::getHealthState() const {
    return healthState;
}

void Person::setHealthState(HealthState healthState) {
    Person::healthState = healthState;
}

const std::pair<double, double> &Person::getPosition() const {
    return position;
}

void Person::setPosition(double x, double y) {
    Person::position = std::pair<double, double>(x, y);
}

const std::pair<double, double> &Person::getDirection() const {
    return direction;
}

void Person::setDirection(double x, double y) {
    Person::direction = std::pair<double, double>(x, y);
}

Box *Person::getBox() const {
    return box;
}

void Person::setBox(Box *box) {
    Person::box = box;
}
