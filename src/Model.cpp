#include "Model.hpp"
#include <algorithm>

void Model::setUp() {
    box = Box(n);
    virus = Virus(prob, radius);
    people = std::vector<Person>(n, Person());
}
