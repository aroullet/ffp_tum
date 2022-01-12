//
// Created by wenz on 26.12.21.
//

#include "InfectedPerson.hpp"

InfectedPerson::InfectedPerson() : Person(HealthState::INFECTED) {
    s_infected_people.push_back(this);
}

InfectedPerson::InfectedPerson(Person &person) {
    if(p_box){
        healthState = HealthState::INFECTED;
        dest = person.dest;
        this->direction = person.direction;
        s_infected_people.push_back(this);
    }else{
        std::cout << "The People don't know where to go!" << std::endl;
        exit(1);
    }
}

bool InfectedPerson::checkHealthState()
{
    if ((1.0*rand())/RAND_MAX <= s_virus->recoveryProb) {
    healthState = HealthState::RECOVERED;
    return true;
    }
    return false;
}
