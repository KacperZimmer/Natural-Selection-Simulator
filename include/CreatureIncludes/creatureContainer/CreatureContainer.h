
#ifndef EXAMPLE_CREATURECONTAINER_H
#define EXAMPLE_CREATURECONTAINER_H
#include "../../../include/IObserver.h"

#include <vector>
#include "../creature.h"
#include "../../ObserverSubject.h"
#include "../../DataManager/DataManager.h"
#include "../../EntityFactoryInclude/entityFactory.h"

class CreatureContainer : ObserverSubject{

private:

    //TODO this should be a list
    int day{};

    std::vector<std::unique_ptr<Creature>> creatureContainer{};
    std::unique_ptr<entityFactory> factory;
    size_t countSleeping{};
    size_t size{};
    std::shared_ptr<DataManager> dataHub{};
    float sizeCreature{};
    float seeingRange{};
    float speed{};



    void updateStatus(FoodContainer& foodContainer);
    void processEndOfDayCycle(FoodContainer& foodContainer);
    void cleanUpTheCreature(size_t index);
    void generateNewCreature(size_t index);


public:
    void slowDownRelativeSpeed();
    void inreaseRelativeSpeed();
    size_t getAive();
    void render();
    float startingXpos{20};
    float startingYpos{20};

    const float timeToUpdate{1.f};
    float shouldUpdate{};
    float deltatime{};
    void generate(int quantity);
    void update(FoodContainer& foodContainer);

    void generateSymmetricaly(size_t quantity, float radius);
    explicit CreatureContainer(std::unique_ptr<entityFactory>& factory, float size, float seeingRange, float speed);
    void turnOnVision();
    void turnOffVision();
    void generateCentre(size_t quantity, float radius);

    const std::shared_ptr<DataManager> &getDataHub() const;

};


#endif //EXAMPLE_CREATURECONTAINER_H
