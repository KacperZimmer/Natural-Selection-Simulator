
#ifndef EXAMPLE_DATAMANAGER_H
#define EXAMPLE_DATAMANAGER_H

#include <unordered_map>
#include "../IObserver.h"
#include "../CreatureIncludes/Genome.h"


class DataManager {

private:

    std::unordered_map<int,float> velocityPerDay{};
    std::unordered_map<int,float> sizePerDay{};
    std::unordered_map<int, Genome> genomePerDay{};


public:
    const std::unordered_map<int, float> &getVelocityPerDay() const;
    const std::unordered_map<int, float> &getSizePerDay() const;
    const std::unordered_map<int, Genome> &getGenomePerDay() const;


};


#endif //EXAMPLE_DATAMANAGER_H
