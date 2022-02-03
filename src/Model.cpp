#include "Model.hpp"
#include "Virus.hpp"
#include <algorithm>
#include "randomGenerator.hpp"

constexpr float DEFAULT_RECOVERY_PROB = 0.0002;
constexpr unsigned CRITICAL_TIME_STEPS = 1;

constexpr double DEFAULT_SPEED = 10;
constexpr double DEFAULT_SIZE = 30;

Model::Model(unsigned N, unsigned iN,unsigned width, unsigned height, float prob, float radius)
    : virus{prob, radius, DEFAULT_RECOVERY_PROB, CRITICAL_TIME_STEPS}, box{width, height} {

    // Important, these have to be initialized before the people vector
    Person::s_size = DEFAULT_SIZE;
    Person::sp_box = std::make_shared<Box>(box);
    Person::s_speed = DEFAULT_SPEED;
    Person::s_virus = std::make_shared<Virus>(virus);//new Virus{0.5, 10.0, 2.0, 1}

    people = std::vector<std::shared_ptr<Person>>(N-iN);
    for (auto& p: people) {
        p = std::make_shared<Person>();
    }
    infected = std::vector<std::shared_ptr<Person>>(iN);
    for (auto& p : infected){
        p = std::make_shared<Person>(HealthState::INFECTED);
    }
}

void Model::movePeople(const std::vector<std::shared_ptr<Person>>& peopleVector) {
    for (const auto& person : peopleVector)
        person->updatePosition();
}

//helping methodsfor update state which we only declare here, since they should not be used by other classes
void updateModelArray(std::vector<std::shared_ptr<Person>> &newlyChangedP, std::vector<int> &positionNewlyChangedP, std::vector<std::shared_ptr<Person>> &people1, std::vector<std::shared_ptr<Person>> &people2){
    unsigned int numberNewlyChangedP = positionNewlyChangedP.size();
    for(unsigned i = 1; i <= numberNewlyChangedP; i++){
        people1.push_back(newlyChangedP[numberNewlyChangedP-i]);
        people2.erase(people2.begin()+positionNewlyChangedP[numberNewlyChangedP-i]);
    }
}
//helping methodsfor update state which we only declare here, since they should not be used by other classes
void checkModelArrayUpdates(std::vector<std::shared_ptr<Person>> &newlyChangedP, std::vector<int> &positionNewlyChangedP, std::vector<std::shared_ptr<Person>> &people, std::vector<std::shared_ptr<Person>> *infected=0){
    bool state_changed;
    for (long unsigned i = 0; i < people.size(); i++) {
        if (people[i]->healthState == HealthState::SUSCEPTIBLE && infected) {
            state_changed = people[i]->checkInfection(*infected);
        }else if(people[i]->healthState == HealthState::RECOVERED){
            state_changed = people[i]->checkImmunity();
        }else{
            state_changed = people[i]->checkRecovery();
        }
        if(state_changed){
            newlyChangedP.push_back(people[i]);
            positionNewlyChangedP.push_back(i);
        }
    }
}

void Model::updateState() {

    // New method to keep the code DRY
    movePeople(people);
    movePeople(infected);
    movePeople(recovered);

    std::vector<std::shared_ptr<Person>> newlyInfected;
    std::vector<int> positionNewlyInfected;
    checkModelArrayUpdates(newlyInfected, positionNewlyInfected, people, &infected);

    // Doing it here since people who just got infected should not have the chance to immediately recover
    std::vector<std::shared_ptr<Person>> newlyRecovered;
    std::vector<int> positionNewlyRecovered;
    checkModelArrayUpdates(newlyRecovered, positionNewlyRecovered, infected);

    std::vector<std::shared_ptr<Person>> newlySusceptible;
    std::vector<int> positionNewlySusceptible;
    checkModelArrayUpdates(newlySusceptible, positionNewlySusceptible, recovered);

    updateModelArray(newlyInfected, positionNewlyInfected, infected, people);
    updateModelArray(newlyRecovered, positionNewlyRecovered, recovered, infected);
    updateModelArray(newlySusceptible, positionNewlySusceptible, people, recovered);

    positionNewlyInfected.clear();
    newlyInfected.clear();

    positionNewlyRecovered.clear();
    newlyRecovered.clear();

    positionNewlySusceptible.clear();
    newlySusceptible.clear();
}