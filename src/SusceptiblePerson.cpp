//
// Created by wenz on 26.12.21.
//

#include "SusceptiblePerson.hpp"

SusceptiblePerson::SusceptiblePerson() : Person(HealthState::SUSCEPTIBLE) {
}
SusceptiblePerson::SusceptiblePerson(Person &person) {
    if(p_box){
        healthState = HealthState::SUSCEPTIBLE;
        dest = person.dest;
        this->direction = person.direction;
    }else{
        std::cout << "The People don't know where to go!" << std::endl;
        exit(1);
    }
}
bool SusceptiblePerson::checkHealthState() {
    for(auto person: s_infected_people){
        auto iPerson = std::make_shared<Person>(*person);
        if(calcSquareDistance(iPerson)<s_virus->squareRadius){
            if(++nrHitsPPerson[iPerson] >= s_virus->criticalNrTimeSteps){
                if((1.0*rand())/RAND_MAX<= s_virus->spreadProb){
                    healthState = HealthState::INFECTED;
                    //map can be cleared since this person is now infected
                    nrHitsPPerson.clear();
                    return true;
                }else{
                    nrHitsPPerson[iPerson] = 0;
                }
            }
        }else{
            nrHitsPPerson[iPerson] = 0;
        }
    }
    return false;
}