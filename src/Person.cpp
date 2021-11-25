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
        this->direction = std::pair(xCoord/length, yCoord/length);
    }else{
        std::cout << "The People don't know where to go!" << std::endl;
        exit(1);
    }
};

void Person::updatePosition() {
    /**
     * outOfWindow-Vector pointing from the border to the direction where it penalizes the windowsize
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


HealthState Person::getHealthState() const {
    return healthState;
}

double Person::calcDistance(Person *other){
    auto otherPos = other->getPosition();
    double x = otherPos.first - dest.x;
    double y = otherPos.second - dest.y;
    return sqrt(x*x + y*y);
}
bool Person::updateHealthState(std::vector<Person *> &infectedPeople) {
    for(auto iPerson: infectedPeople){
        if(calcDistance(iPerson)<virus->radius){
            if(++nrHitsPPerson[iPerson] >= virus->criticalNrTimeSteps){
                healthState = HealthState::INFECTED;
                //map can be cleared since this person is now infected
                nrHitsPPerson.clear();
                return true;
            }
        }
    }
    return false;
}

std::pair<double, double> Person::getPosition() {
    return std::pair<double, double>(dest.x, dest.y);
}

void Person::deleteInfectedFromMap(std::vector<Person *> &people) {
    for(auto person : people){
        nrHitsPPerson.erase(person);
    }
}

void Person::deleteInfectedFromMap(Person &person) {
    nrHitsPPerson.erase(&person);
}

void Person::setHealthState(HealthState healthState) {
    Person::healthState = healthState;
}

Box* Person::box;
Virus* Person::virus;
double Person::speed;
double Person::size;

