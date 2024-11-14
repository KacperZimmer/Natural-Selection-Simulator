#include "../../include/DataManagerInc/dataManager.h"


const std::unordered_map<int, float> &DataManager::getVelocityPerDay() const {
    return velocityPerDay;
}

const std::unordered_map<int, float> &DataManager::getSizePerDay() const {
    return sizePerDay;
}

const std::unordered_map<int, Genome> &DataManager::getGenomePerDay() const {
    return genomePerDay;
}
