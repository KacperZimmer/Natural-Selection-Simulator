#include "../../include/DataManagerInc/dataManager.h"

void DataManager::update(float velocity, float size, float seeingRadius, int day) {

    this->velocity = velocity;
    this->size = size;
    this->seeingRadius = seeingRadius;
    this->day = day;

}
