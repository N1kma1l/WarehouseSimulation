#include "utils/RandomGenerator.h"
#include <stdexcept>

RandomGenerator::RandomGenerator() : 
    seed_(std::random_device{}()),
    generator_(seed_) {}

int RandomGenerator::getInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator_);
}

double RandomGenerator::getDouble(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator_);
}

double RandomGenerator::getProbability() {
    return getDouble(0.0, 1.0);
}

bool RandomGenerator::checkProbability(double probability) {
    return getProbability() < probability;
}