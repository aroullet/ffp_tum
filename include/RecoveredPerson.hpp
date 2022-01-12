//
// Created by wenz on 26.12.21.
//

#ifndef FFP_TUM_RECOVEREDPERSON_HPP
#define FFP_TUM_RECOVEREDPERSON_HPP
#include "Person.hpp"


class RecoveredPerson : Person{
    RecoveredPerson();
    RecoveredPerson(int personID);
    bool checkHealthState() override;
};


#endif //FFP_TUM_RECOVEREDPERSON_HPP
