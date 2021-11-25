#include "Model.hpp"
#include <algorithm>

void Model::setUp() {
    box = Box();
    virus = Virus(prob, radius);
    people = std::vector<Person>(N, Person(&box));
    recovered = std::vector<Person>(N); // Initializing with size N to avoid resizing
}

void Model::updateState() {

    for (Person& person : people) {
        person.updatePosition();
        person.updateHealthState();
    }
    
}