#include "Model.hpp"
#include "Virus.hpp"
#include <algorithm>

Model::Model(unsigned int N, unsigned int iN,unsigned int width, unsigned int height, float prob, float radius) {
    box.x = width;
    box.y = height;
    virus.spreadProb = prob;
    virus.radius = radius; //radius and hits are the only thing that matter do far
    virus.criticalNrTimeSteps = 1; // just hitting it once


    // Important, these have to be initialized before the people vector
    Person::s_size = 30;
    Person::p_box = &box;
    Person::s_speed = 10;
    Person::s_virus = &virus;//new Virus{0.5, 10.0, 2.0, 1}

    people = std::vector<std::shared_ptr<Person>>(N-iN);
    for (unsigned int i = 0; i < N-iN; i++ ){
        people[i] = std::make_shared<Person>();
    }
    infected = std::vector<std::shared_ptr<Person>>(iN);
    for (unsigned int i = 0; i < iN; i++ ){
        infected[i] = std::make_shared<Person>(HealthState::INFECTED);
    }
    //recovered = std::vector<Person>(N); // Initializing with size N to avoid resizing
}

void Model::updateState() {
    for (auto person : people) {
        person->updatePosition();
    }
    for (auto person : infected) {
        person->updatePosition();
    }
    std::vector<std::shared_ptr<Person>> newlyInfected;
    std::vector<int> position;
    for (long unsigned int i = 0; i < people.size(); i++) {
        bool state_changed = people[i]->updateHealthState(infected);
        if(state_changed){
            newlyInfected.push_back(people[i]);
            position.push_back(i);
        }

    }
    unsigned int numberNewlyInfected = position.size();
    for(unsigned int i = 1; i <= numberNewlyInfected; i++){
        infected.push_back(newlyInfected[position.size()-i]);
        people.erase(people.begin()+position[numberNewlyInfected-i]);
    }
    position.clear();
    newlyInfected.clear();
}