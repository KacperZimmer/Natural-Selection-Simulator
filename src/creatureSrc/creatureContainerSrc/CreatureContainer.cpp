#include "../../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"
#include <iostream>


void CreatureContainer::render() {

    for(const auto& creature : this->creatureContainer){

        if(creature == nullptr){

            continue;

        }
        creature->render();
    }
}

void CreatureContainer::update(FoodContainer& foodContainer) {

    this->countSleeping = 0;

    updateStatus(foodContainer);
    processEndOfDayCycle(foodContainer);
}

void CreatureContainer::generate(int quantity) {



}

void CreatureContainer::turnOnVision() {

    for(auto& creature : this->creatureContainer){
        if(creature == nullptr){
            continue;
        }
        creature->turnOnVision();
    }
}

void CreatureContainer::turnOffVision() {

    for(auto& creature : this->creatureContainer){
        if(creature == nullptr){
            continue;
        }
        creature->turnOffVision();
    }
}

void CreatureContainer::generateSymmetricaly(size_t quantity,float radius) {

    this->size = quantity;
    int scale = (radius / 10);

    size_t numEachSide = quantity / 4;

    float spacing = (SCREEN_HEIGHT / ((radius) * 2 * static_cast<float> (quantity))) *
                    static_cast<float>((75 * ((scale == 0) ? 1 : scale)));

    std::cout << this->sizeCreature << std::endl;

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < numEachSide; ++j) {


            std::unique_ptr<Creature> currentCreature = std::move(factory->prepareOne(
                    this->startingXpos,
                    this->startingYpos,
                    this->sizeCreature, 2.f,
                    this->seeingRange));

            creatureContainer.push_back(std::move(currentCreature));

            switch (i){

                case 0:
                    this->startingYpos += spacing;
                    break;

                case 1:
                    this->startingXpos += spacing;
                    break;

                case 2:
                    this->startingYpos -= spacing;
                    break;

                case 3:
                    this->startingXpos -= spacing;
                    break;

                default:
                    std::cout << "wrong indexing" << std::endl;
            }
        }
    }
}

CreatureContainer::CreatureContainer(std::unique_ptr<entityFactory> &factory,  float size, float seeingRange, float speed) {

    this->sizeCreature = size;
    this->seeingRange = seeingRange;
    this->speed = speed;

    this->factory = std::move(factory);
}

void CreatureContainer::generateNewCreature(size_t index) {

    if(index >= this->creatureContainer.size()){
        throw std::out_of_range("index out of the array");
    }

    this->creatureContainer.emplace_back(
            std::move(

                    factory->makeChild(

                            (this->creatureContainer[index])->getGenome(),
                            (this->creatureContainer[index]->getPosition())

                    )
            )
    );

}

void CreatureContainer::cleanUpTheCreature(size_t index) {

    if(index >= this->creatureContainer.size()){
        throw std::out_of_range("index out of the array");
    }
    deltatime = GetFrameTime();

    if (this->shouldUpdate <= this->timeToUpdate) {
        this->shouldUpdate += deltatime;

    } else {
        creatureContainer[index].reset();
        creatureContainer.erase(creatureContainer.begin() + index);

        --this->size;
        this->shouldUpdate = 0.f;
    }

}

void CreatureContainer::inreaseRelativeSpeed() {

    short currentRelativeSpeed{};
    for(const auto & x : this->creatureContainer){


        currentRelativeSpeed = x->getRelativeSpeedFactor();
        currentRelativeSpeed *= 2;

        if(currentRelativeSpeed <= 8) {
            x->setRelativeSpeedFactor(currentRelativeSpeed);

        }else{

            x->setRelativeSpeedFactor(8);
        }

    }

}


void CreatureContainer::slowDownRelativeSpeed() {

    short currentRelativeSpeed{};

    for(const auto & x : this->creatureContainer){

        currentRelativeSpeed = x->getRelativeSpeedFactor();
        currentRelativeSpeed /= 2;

        if(currentRelativeSpeed >= 1){
            x->setRelativeSpeedFactor(currentRelativeSpeed);

        }else{
            x->setRelativeSpeedFactor(1);
        }

    }
}

void CreatureContainer::updateStatus(FoodContainer& foodContainer) {

    for (size_t i = 0; i < this->creatureContainer.size(); ++i) {

        if(this->creatureContainer[i] == nullptr){
            continue;
        }

        if (creatureContainer[i]->isDead()) {
            cleanUpTheCreature(i);
            continue;
        }

        if(creatureContainer[i]->isSleeping() == true){
            ++countSleeping;
        }


        creatureContainer[i]->update(foodContainer);


    }
}

void CreatureContainer::processEndOfDayCycle(FoodContainer &foodContainer) {
    if(countSleeping == size){
        for(size_t i = 0; i < this->creatureContainer.size(); ++i) {

            if (this->creatureContainer[i] == nullptr) {
                continue;
            }

            if (creatureContainer[i]->shouldReproduce() == true) {
                this->generateNewCreature(i);
                ++this->size;
            }
        }
        foodContainer.generateFood(foodContainer.getNumOfFoodToGenerate());

        for(const auto & i : this->creatureContainer){

            if(i == nullptr){
                continue;
            }


            i->wakeUp();
            ++day;
            notify(i->getSpeed(), i->getRadius(), i->getGenome().getSeeingRadius(),day);
        }

    }

}



