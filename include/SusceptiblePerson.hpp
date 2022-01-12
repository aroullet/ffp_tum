//
// Created by wenz on 26.12.21.
//

#ifndef FFP_TUM_SUSCEPTIBLEPERSON_HPP
#define FFP_TUM_SUSCEPTIBLEPERSON_HPP
#include "Person.hpp"


class SusceptiblePerson : Person{
public:
    SusceptiblePerson();
    SusceptiblePerson(Person &person);
    bool checkHealthState() override;
};


#endif //FFP_TUM_SUSCEPTIBLEPERSON_HPP
