#ifndef FFP_TUM_MODEL_H
#define FFP_TUM_MODEL_H

#include <vector>
#include "Box.hpp"
#include "Virus.hpp"
#include "Person.hpp"

class Model {
private:
    unsigned int n;
    Box box;
    Virus virus;
    std::vector<Person> people;

    void setUp();

public:
    Model(unsigned int n, unsigned int sideLength, float prob, float radius) {setUp()};
};


#endif //FFP_TUM_MODEL_H
