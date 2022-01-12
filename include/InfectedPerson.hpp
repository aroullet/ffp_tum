//
// Created by wenz on 26.12.21.
//

#ifndef FFP_TUM_INFECTEDPERSON_HPP
#define FFP_TUM_INFECTEDPERSON_HPP
#include "Person.hpp"


class InfectedPerson : Person {
public:
    InfectedPerson();
    InfectedPerson(Person &person);
    bool checkHealthState() override;
};


#endif //FFP_TUM_INFECTEDPERSON_HPP
