
#ifndef EXAMPLE_DATAMANAGER_H
#define EXAMPLE_DATAMANAGER_H

#include "../IObserver.h"

class DataManager : public IObserver{

private:

    float velocity{};
    float size{};
    float seeingRadius{};
    int day{};

public:

    void update(float velocity, float size, float seeingRadius, int day) override;

};


#endif //EXAMPLE_DATAMANAGER_H
