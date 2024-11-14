
#include "../../include/CreatureIncludes/movement.h"
#include "raymath.h"
#include <random>
#include <iostream>


void Movement::move() {

    /*
     * Updates player position after some time
     */

    goBackToLegalPositionIfOutOfBound();

    this->shouldUpdatePosition += deltaTime;

    if(this->shouldUpdatePosition >= this->timeAfterPositionShouldBeUpdated){
        this->shouldUpdatePosition = 0.f;

        this->xDirection *= this->generateRandomDirection();
        this->yDirection *= this->generateRandomDirection();

    }else{
        this->currentPosition.x += static_cast<float>(this->speed * this->relativeSpeedFactor * static_cast<float>(xDirection));
        this->currentPosition.y += static_cast<float>(this-> speed * this->relativeSpeedFactor* static_cast<float>(yDirection));
    }
}

int Movement::generateRandomDirection() const{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    int result = dis(gen);
    return (result == 0) ? -1 : 1;
}





void Movement::goToTarget(const Vector2& target) {


    if(!checkIfTargetIsReached(target)) {
        //TODO violates single resp, function takes player to the target and checks if return whether he reached the target
        Vector2 direction = Vector2Normalize(Vector2Subtract(target, this->currentPosition));


        this->currentPosition.x += direction.x * this->speed * this->relativeSpeedFactor;
        this->currentPosition.y += direction.y * this->speed * this->relativeSpeedFactor;
    }


}


Movement::Movement(float creatureRadius, float speed) : Movable(creatureRadius, speed) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0169255, 0.05);
    this->deltaTime = dis(gen);
}


bool Movement::checkIfTargetIsReached(Vector2 target) {
    if(Vector2Distance(this->currentPosition, target) <= this->creatureRadius){
        return true;
    }
    return false;
}





