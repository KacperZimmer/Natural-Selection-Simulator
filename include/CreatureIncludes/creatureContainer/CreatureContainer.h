
#ifndef EXAMPLE_CREATURECONTAINER_H
#define EXAMPLE_CREATURECONTAINER_H
#include "../../../include/IObserver.h"

#include <vector>
#include "../creature.h"
#include "../../ObserverSubject.h"
#include "../../EntityFactoryInclude/entityFactory.h"

class CreatureContainer : ObserverSubject{

private:

    //TODO this should be a list
    int day{};

    std::vector<std::unique_ptr<Creature>> creatureContainer{};
    std::unique_ptr<entityFactory> factory;
    size_t countSleeping{};
    std::vector<IObserver> observers{};
    size_t size{};

    void updateStatus(FoodContainer& foodContainer);
    void processEndOfDayCycle(FoodContainer& foodContainer);
    void cleanUpTheCreature(size_t index);
    void generateNewCreature(size_t index);


public:
    void slowDownRelativeSpeed();
    void inreaseRelativeSpeed();
    void render();
    float startingXpos{20};
    float startingYpos{20};

    const float timeToUpdate{1.f};
    float shouldUpdate{};
    float deltatime{};
    void generate(int quantity);
    void update(FoodContainer& foodContainer);


    void generateSymmetricaly(size_t quantity, float radius);
    explicit CreatureContainer(std::unique_ptr<entityFactory>& factory);
    void turnOnVision();
    void turnOffVision();

};


#endif //EXAMPLE_CREATURECONTAINER_H
