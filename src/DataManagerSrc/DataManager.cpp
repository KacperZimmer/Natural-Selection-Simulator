

#include "../../include/DataManager/DataManager.h"
#include <iostream>
void DataManager::update(float velocity, float size, float seeingRadius, int day, size_t numOfOrganisms) {
    if (day != currentDay) {
//        std::cout << currentDay << " to jest current day " << day << "\n";

        if (numOfOrganisms > 0 && currentDay != -1) {
            DataPerDay summary;
            summary.day = currentDay;
            summary.avgVelPerDay = this->velocity / numOfOrganisms;
            summary.avgSizePerDay = this->size / numOfOrganisms;
            summary.avgSeeingRangePerDay = this->seeingRange / numOfOrganisms;

            history.push_back(summary);

        }

        currentDay = day;
        this->velocity = 0;
        this->size = 0;
        this->seeingRange = 0;
    }

    this->velocity += velocity;
    this->size += size;
    this->seeingRange += seeingRadius;

}



