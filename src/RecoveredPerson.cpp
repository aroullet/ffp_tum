//
// Created by wenz on 26.12.21.
//

#include "RecoveredPerson.hpp"

RecoveredPerson::RecoveredPerson() : Person(HealthState::RECOVERED) {
}

RecoveredPerson::RecoveredPerson(int personID) {
    if(p_box){
        auto person = *s_infected_people[personID];
        healthState = HealthState::RECOVERED;
        dest = person.dest;
        this->direction = person.direction;
        //delete entry in s_infected_people
    }else{
        std::cout << "The People don't know where to go!" << std::endl;
        exit(1);
    }
}

bool RecoveredPerson::checkHealthState()
{
    if ((1.0*rand())/RAND_MAX <= s_virus->recoveryProb) {
        healthState = HealthState::SUSCEPTIBLE;
        return true;
    }
    return false;
}