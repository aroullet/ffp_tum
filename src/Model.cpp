#include "Model.hpp"
#include "Virus.hpp"
#include <algorithm>

Model::Model(unsigned int N, unsigned int width, unsigned int height, float prob, float radius) {
    box.x = width;
    box.y = height;
    virus.spreadProb = prob;
    virus.radius = radius;

    // Important, these have to be initialized before the people vector
    Person::s_size = 30;
    Person::p_box = &box;
    Person::s_speed = 10;

    people = std::vector<Person>(N);
    for (auto i = 0; i < N; i++ )
        people[i] = Person();
    recovered = std::vector<Person>(N); // Initializing with size N to avoid resizing
}

void Model::updateState() {
    for (Person& person : people) {
        person.updatePosition();
    }
}