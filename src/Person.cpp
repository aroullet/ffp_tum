#include "Person.hpp"
#include <random>

Person::Person(HealthState state) {
    if(sp_box){
        healthState = state;
        dest.h = s_size/2;
        dest.w = s_size/2;
        dest.x = sp_box->x0+(1.0 * rand()*sp_box->x)/RAND_MAX;
        dest.y = sp_box->y0+(1.0 * rand()*sp_box->y)/RAND_MAX;

        double xCoord= (1.0 * rand()-0.5*RAND_MAX);
        double yCoord= (1.0 * rand()-0.5*RAND_MAX);
        double length = sqrt(xCoord*xCoord + yCoord * yCoord);
        this->direction = std::pair(xCoord/length, yCoord/length);
    }else{
        std::cerr << "The People don't know where to go!" << std::endl;
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
    std::pair<double, double> newDirection = direction;

    if(dest.x + direction.first*s_speed+dest.w>sp_box->x + sp_box->x0){
        outOfWindow.first = (dest.x + direction.first*s_speed+dest.w) - sp_box->x - sp_box->x0;
        newDirection.first = -this->direction.first;
    }
    if(dest.y + direction.second*s_speed+dest.h>sp_box->y + sp_box->y0){
        outOfWindow.second = (dest.y + direction.second*s_speed+dest.h) - sp_box->y - sp_box->y0;
        newDirection.second = -this->direction.second;
    }
    if(dest.x + direction.first*s_speed<sp_box->x0){
        outOfWindow.first = (dest.x + direction.first*s_speed) - sp_box->x0;
        newDirection.first = -this->direction.first;
    }
    if(dest.y + direction.second*s_speed<sp_box->y0){
        outOfWindow.second = (dest.y + direction.second*s_speed) - sp_box->y0;
        newDirection.second = -this->direction.second;
    }
    dest.x += (direction.first*s_speed - 2*outOfWindow.first);
    dest.y +=  (direction.second*s_speed - 2*outOfWindow.second);
    direction = newDirection;
}


double Person::calcSquareDistance(std::shared_ptr<Person> other) const {
    auto otherPos = other->getPosition();
    double x = otherPos.first - dest.x;
    double y = otherPos.second - dest.y;
    return x*x + y*y;
}

bool Person::checkInfection(std::vector<std::shared_ptr<Person>> &infectedPeople) {
    for(auto iPerson: infectedPeople){
        //std::cout << calcDistance(iPerson) << ":" << s_virus->radius << std::endl;
        if (calcSquareDistance(iPerson) < s_virus->squareRadius) {
            if (++nrHitsPPerson[iPerson] >= s_virus->criticalNrTimeSteps) {
                if ((1.0 * rand()) / RAND_MAX <= s_virus->spreadProb) {
                    healthState = HealthState::INFECTED;
                    //map can be cleared since this person is now infected
                    nrHitsPPerson.clear();
                    return true;
                } else {
                    nrHitsPPerson[iPerson] = 0;
                }
            }
        }else {
            nrHitsPPerson[iPerson] = 0;
        }
    }
    return false;
}

bool Person::checkRecovery() {
    // Found online, but there might be a better way.
    //std::random_device rd;
    //std::default_random_engine eng(rd());
    //std::uniform_real_distribution<float> distr(0, 1);
    //float randomNumber = distr(eng);

    if ((1.0*rand())/RAND_MAX <= s_virus->recoveryProb) {
        healthState = HealthState::RECOVERED;
        return true;
    }
    return false;
}

std::pair<double, double> Person::getPosition() const {
    return {dest.x, dest.y};
}


// Need to define static variables before assignment within Model.cpp
std::shared_ptr<Box> Person::sp_box;
std::shared_ptr<Virus> Person::s_virus;
double Person::s_speed;
double Person::s_size;
