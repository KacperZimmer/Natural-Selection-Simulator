#include "../../include/CreatureIncludes/creature.h"
#include <cmath>
#include <iostream>


void Creature::turnOnVision() {
    /*
     * Turns on the vision range for each character
     */

    bool currentState = this->eyes.ShouldDisplayVisionRange();

    this->eyes.setShouldDisplayVisionRange(!currentState);

}

void Creature::turnOffVision() {
    //TODO both turn off and turn on can be made into one function

    bool currentState = this->eyes.ShouldDisplayVisionRange();
    if(currentState){
        currentState = false;
    }
    this->eyes.setShouldDisplayVisionRange(currentState);
}

void Creature::render() {

    DrawCircle(static_cast<int>(movement->getPosition().x), static_cast<int>(movement->getPosition().y),this->getRadius(), this->currentColor);
}

double Creature::calcEnergyLoss() const {

    return (pow(this->genome.getSize(), 3) * pow(this->getSpeed(),2) ) / 1000 / this->getRadius();
}



void Creature::headToSleep(Vector2 target) {

    if(!this->movement->checkIfTargetIsReached(target)) {

        movement->goToTarget(movement->getClosestPathToBoundaryVector());
        this->updateEnergy();

    }else{
        this->sleeping = true;
    }
}


void Creature::die() {
    this->isAlive = false;
    this->currentColor = this->deathColor;
}



void Creature::update(FoodContainer& foodContainer) {


    if(this->genome.getEnergy() <= 0 || (foodContainer.getFoodNum() == 0 && foodConsumed == 0)){
        die();
        return;
    }
    this->updateVision();

    size_t nearestFoodInVectorIndex = this->eyes.isFoodInRange(foodContainer.getFoodArray());

    if(nearestFoodInVectorIndex != -1){
        this->updateMovement(nearestFoodInVectorIndex,foodContainer, this->getRelativeSpeedFactor());

    }else if(this->sleeping == true){
        this->reproductionStatus = this->checkIfShouldReproduce();
        this->genome.setEnergy(5000);

    }else if(this->foodConsumed >= 2 || this->foodConsumed == 1 && this->startingEnergy / 1.5 >= this->getEnergy()){

        this->headToSleep(movement->getClosestPathToBoundaryVector());

    }else{
        movement->setRelativeSpeedFactor(this->genome.getRelativeSpeedFact());
        this->movement->move();
        this->updateEnergy();

    }

}

void Creature::updateEnergy() {

    float temp = this->genome.getEnergy();
    temp -= calcEnergyLoss();
    this->genome.setEnergy(temp);
}

void Creature::updateMovement(size_t nearestFoodIndex,FoodContainer& foodContainer, short speedFactor) {

    Vector2 currentPathEndPoint = foodContainer.getVectorAtIndex(nearestFoodIndex);
    float temp{};
    movement->setRelativeSpeedFactor(speedFactor);

    if(!this->movement->checkIfTargetIsReached(currentPathEndPoint)){
        movement->goToTarget(currentPathEndPoint);

    }else{
        temp = this->genome.getEnergy();
        temp += 500;
        this->genome.setEnergy(temp);
        foodContainer.deleteFood(nearestFoodIndex);
        ++this->foodConsumed;
    }

    this->updateEnergy();

}

void Creature::updateVision() {


    this->eyes.setHightlightPositionVector(this->movement->getPosition());

    if(eyes.ShouldDisplayVisionRange()){
        eyes.highlightVisionRange();
    }

}



void Creature::setRelativeSpeedFactor(short speedFactor) {

    this->genome.setRelativeSpeedFact(speedFactor);

}

void Creature::setMovement(std::unique_ptr<Movable>& movement) {
    this->movement = std::move(movement);

}

void Creature::setSeeing(Seeing &eyes) {
    this->eyes = eyes;
}

bool Creature::isDead() const {
    return !this->isAlive;
}

bool Creature::shouldReproduce() const {
    return this->reproductionStatus;
}


Genome& Creature::getGenome() {
    return this->genome;
}

const Vector2& Creature::getPosition() const{
    return this->movement->getPosition();
}

float Creature::getRadius() const{
    return this->genome.getSize();
}

float Creature::getSpeed() const {
    return this->genome.getVelocity();
}

float Creature::seeingRange() const{
    return this->eyes.getSeeingRange();
}

bool Creature::isSleeping() const {
    return this->sleeping;
}

void Creature::wakeUp() {
    this->foodConsumed = 0;
    this->sleeping = false;
}

bool Creature::checkIfShouldReproduce() const {
    if(this->foodConsumed >= 2) return true;
    return false;
}

double Creature::getEnergy() const {
    return this->genome.getEnergy();
}

short Creature::getRelativeSpeedFactor() const {
    return genome.getRelativeSpeedFact();
}













