#include "Model.hpp"
#include "Virus.hpp"
#include <algorithm>

Model::Model(unsigned int N, unsigned int iN,unsigned int width, unsigned int height, float prob, float radius) {
    box.x = width;
    box.y = height;
    virus.spreadProb = prob;
    virus.radius = radius; //radius and hits are the only thing that matter do far
    virus.criticalNrTimeSteps = 1; // just hitting it once
    virus.recoveryProb = 0.003; // 0.3% chance to recover at each time step

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
    recovered.reserve(N); // Don't call constructor as it needs to be empty at first.

    anyRecovered = false; // flag to check if anyone has recovered
}

void Model::movePeople(std::vector<std::shared_ptr<Person>> peopleVector) {
    for (auto person : peopleVector)
        person->updatePosition();
}

void Model::updateState() {

    // New method to keep the code DRY
    movePeople(people);
    movePeople(infected);

    if (anyRecovered)
        movePeople(recovered);

    // But ironically there's a lot of repetition in the next section :D
    std::vector<std::shared_ptr<Person>> newlyInfected;
    std::vector<int> positionNewlyInfected;
    for (long unsigned int i = 0; i < people.size(); i++) {
        bool state_changed = people[i]->checkInfection(infected);
        if (state_changed) {
            newlyInfected.push_back(people[i]);
            positionNewlyInfected.push_back(i);
        }
    }
    // Doing it here since people who just got infected should not have the chance to immediately recover
    std::vector<std::shared_ptr<Person>> newlyRecovered;
    std::vector<int> positionNewlyRecovered;
    for (long unsigned int i = 0; i < infected.size(); i++) {
        bool state_changed = infected[i]->checkRecovery();
        if(state_changed){
            anyRecovered = true;
            newlyRecovered.push_back(infected[i]);
            positionNewlyRecovered.push_back(i);
        }
    }
    unsigned int numberNewlyInfected = positionNewlyInfected.size();
    for(unsigned int i = 1; i <= numberNewlyInfected; i++){
        infected.push_back(newlyInfected[numberNewlyInfected-i]);
        people.erase(people.begin()+positionNewlyInfected[numberNewlyInfected-i]);
    }

    unsigned int numberNewlyRecovered = positionNewlyRecovered.size();
    for(unsigned int j = 1; j <= numberNewlyRecovered; j++){
        recovered.push_back(newlyRecovered[numberNewlyRecovered-j]);
        infected.erase(infected.begin()+positionNewlyRecovered[numberNewlyRecovered-j]);
    }

    positionNewlyInfected.clear();
    newlyInfected.clear();

    positionNewlyRecovered.clear();
    newlyRecovered.clear();
}