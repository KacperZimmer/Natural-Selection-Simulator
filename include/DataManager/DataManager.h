

#ifndef EXAMPLE_DATAMANAGER_H
#define EXAMPLE_DATAMANAGER_H
#include "../IObserver.h"
#include <vector>

struct DataPerDay{
    float avgSizePerDay{};
    float avgVelPerDay{};
    float avgSeeingRangePerDay{};
    int day{};
};
class DataManager : public IObserver{
public:
    const std::vector<DataPerDay>& getHistory() const {
        return history;
    }
    int currentDay{};

    float velocity{};
    float seeingRange{};
    float size{};

    std::vector<DataPerDay> history{};
    void update(float velocity, float size, float seeingRadius, int day, size_t numOfOrganisms) override;

};


#endif //EXAMPLE_DATAMANAGER_H
