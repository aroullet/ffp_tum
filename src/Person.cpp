#include "Person.hpp"

Person::Person() {
    if(box){
        this->box = box;
        dest.h = size/2;
        dest.w = size/2;
        dest.x = (1.0 * rand()*box->x)/RAND_MAX;
        dest.y = (1.0 * rand()*box->y)/RAND_MAX;
        double xCoord= (0.5 * (rand()-RAND_MAX))/RAND_MAX;
        double yCoord= (0.5 * (rand()-RAND_MAX))/RAND_MAX;
        double length = sqrt(xCoord*xCoord + yCoord * yCoord);
        this->setDirection(xCoord/length, yCoord/length);
    }else{
        std::cout << "e.what()" << std::endl;
    }
};

void Person::updatePosition() {
    /**
     * Vector pointing from the border to the direction where it penalizes the windowsize
     *              |           * Person at the first state
     *              |           (*) the newstate by just using the given direction
     *            * | (*)
     * ...__________|
     * so the vector outOfWindow  points from the border to the (*) point so it must
     * be subtracted twice from (*) to see the actual point bounced off from the wall
     *
     * Important the direction needs to be updated as well.
     */
    std::pair<double, double> outOfWindow{0,0};
    if(dest.x + direction.first*speed>box->x){
        outOfWindow.first = (dest.x + direction.first*speed) - box->x;
        this->direction.first = -this->direction.first;
    }
    if(dest.y + direction.second*speed>box->y){
        outOfWindow.second = (dest.y + direction.second*speed) - box->y;
        this->direction.second = -this->direction.second;
    }
    if(dest.x + direction.first*speed<0){
        outOfWindow.first = (dest.x + direction.first*speed);
        this->direction.first = -this->direction.first;
    }
    if(dest.y + direction.second*speed>0){
        outOfWindow.second = (dest.y + direction.second*speed);
        this->direction.second = -this->direction.second;
    }
    dest.x = dest.x + direction.first*speed - 2*outOfWindow.first;
    dest.y = dest.y + direction.second*speed - 2*outOfWindow.second;
}

void Person::calcDistance(Person other){
    //auto otherPos = other.getPosition();
    //double x = otherPos.first - position.first;
    //double y = otherPos.second - position.second;
    //return sqrt(x*x + y*y);
}

HealthState Person::getHealthState() const {
    return healthState;
}

void Person::setHealthState(HealthState healthState) {
    Person::healthState = healthState;
}

const std::pair<double, double> &Person::getDirection() const {
    return direction;
}

void Person::setDirection(const double &xDirection, const double &yDirection) {
    Person::direction.first = xDirection;
    Person::direction.second = yDirection;
}

bool Person::updateHealthState(std::vector<Person *> &infectedPeople) {
    return false;
}

Box* Person::box;
double Person::speed;
double Person::size;

