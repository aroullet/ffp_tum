//
// Created by skikk on 03.02.22.
//
#include "randomGenerator.hpp"

double generateRandom(int minimum, int maximum) {
    return minimum+(1.0 * rand()/RAND_MAX*(maximum-minimum));
}