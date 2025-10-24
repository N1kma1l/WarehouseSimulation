#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>
#include <vector>
#include <stdexcept>

class RandomGenerator {
    public:
    RandomGenerator();
    
    unsigned int getSeed() const {
        return seed_;
    }
    
    int getInt(int min, int max);
    double getDouble(double min, double max);
    // Метод генерации случайного double в диапазоне [0.0, 1.0]
    double getProbability();
    // Метод проверки события с заданной вероятностью
    bool checkProbability(double probability);
    
    // Метод выбора случайного элемента из вектора
    template<typename T>
    const T& getRandomElement(const std::vector<T>& elements) {
        if (elements.empty()) {
            throw std::invalid_argument("Empty vector in getRandomElement");
        }
        int index = getInt(0, elements.size() - 1);
        return elements[index];
    }

    private:
    unsigned int seed_;
    std::mt19937 generator_;
};

#endif