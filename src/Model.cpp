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

void Model::updateState() {

    // New method to keep the code DRY
    movePeople(people);
    movePeople(infected);
    movePeople(recovered);

    // The next few blocks have a lot of repetition, need to wrap it up in a nice function that takes a callback function as argument.
    std::vector<std::shared_ptr<Person>> newlyInfected;
    std::vector<int> positionNewlyInfected;
    for (long unsigned i = 0; i < people.size(); i++) {
        bool state_changed = people[i]->checkInfection(infected);
        if (state_changed) {
            newlyInfected.push_back(people[i]);
            positionNewlyInfected.push_back(i);
        }
    }
    // Doing it here since people who just got infected should not have the chance to immediately recover
    std::vector<std::shared_ptr<Person>> newlyRecovered;
    std::vector<int> positionNewlyRecovered;
    for (long unsigned i = 0; i < infected.size(); i++) {
        bool state_changed = infected[i]->checkRecovery();
        infected[i]->latency?infected[i]->latency--:0;
        if(state_changed){
            newlyRecovered.push_back(infected[i]);
            positionNewlyRecovered.push_back(i);
        }
    }
    std::vector<std::shared_ptr<Person>> newlySusceptible;
    std::vector<int> positionNewlySusceptible;
    for (long unsigned i = 0; i < recovered.size(); i++) {
        if(recovered[i]->immunity){
            recovered[i]->immunity--;
            std::cout << recovered[i]->immunity<<std::endl;
        }else{
            newlySusceptible.push_back(infected[i]);
            positionNewlySusceptible.push_back(i);
        }
    }
    unsigned int numberNewlyInfected = positionNewlyInfected.size();
    for(unsigned i = 1; i <= numberNewlyInfected; i++){
        infected.push_back(newlyInfected[numberNewlyInfected-i]);
        people.erase(people.begin()+positionNewlyInfected[numberNewlyInfected-i]);
    }

    unsigned int numberNewlyRecovered = positionNewlyRecovered.size();
    for(unsigned j = 1; j <= numberNewlyRecovered; j++){
        recovered.push_back(newlyRecovered[numberNewlyRecovered-j]);
        infected.erase(infected.begin()+positionNewlyRecovered[numberNewlyRecovered-j]);
    }
    unsigned int numberNewlySusceptible = positionNewlySusceptible.size();
    for(unsigned j = 1; j <= numberNewlySusceptible; j++){
        newlySusceptible[numberNewlySusceptible-j]->healthState=HealthState::SUSCEPTIBLE;
        newlySusceptible[numberNewlySusceptible-j]->latency = generateRandom(100, 1000);
        newlySusceptible[numberNewlySusceptible-j]->immunity = generateRandom(100, 1000);
        people.push_back(newlySusceptible[numberNewlySusceptible-j]);
        recovered.erase(recovered.begin()+positionNewlySusceptible[numberNewlySusceptible-j]);
        std::cout<<"back to susceptible"<<std::endl;
    }

    positionNewlyInfected.clear();
    newlyInfected.clear();

    positionNewlyRecovered.clear();
    newlyRecovered.clear();

    positionNewlySusceptible.clear();
    newlySusceptible.clear();
}