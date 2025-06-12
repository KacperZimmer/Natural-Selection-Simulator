
#include "../../include/CreatureIncludes/seeing.h"
#include <iostream>
#include <algorithm>
#include "raymath.h"
void Seeing::highlightVisionRange() {

    if(this->shouldDisplayVisionRange){
        DrawCircle(static_cast<int>(this->hightlightPositionVector.x), static_cast<int>(this->hightlightPositionVector.y), this->seeingRange, Color{25, 102, 209,125});
    }
}

void Seeing::setShouldDisplayVisionRange(bool shouldDisplayVisionRang) {
    this->shouldDisplayVisionRange = shouldDisplayVisionRang;
}

void Seeing::setHightlightPositionVector(const Vector2& hightlightPositionVector) {
    this->hightlightPositionVector = hightlightPositionVector;
}

bool Seeing::ShouldDisplayVisionRange() const {
    return this->shouldDisplayVisionRange;
}

int Seeing::isFoodInRange(const std::vector<std::unique_ptr<Food>>& foodVector){


    this->closestDistance = 3.402823466e+38F;

    float currentDistance;
    int indexToReturn{-1};
    for(int i = 0; i < foodVector.size(); ++i){

        if(foodVector[i] == nullptr){
            continue;
        }

        currentDistance = Vector2Distance(hightlightPositionVector, foodVector[i]->getPosition());
        if(this->closestDistance >= currentDistance){
            this->closestDistance = std::min(this->closestDistance, currentDistance);
            indexToReturn = i;
        }
    }

    return this->closestDistance <= this->seeingRange + 1.f * 2 ? indexToReturn : -1;
}

Seeing::Seeing() {
    this->seeingRange = 0.f;

}

Seeing::Seeing(const Vector2 &posToDrawIn, float seeingRange) {
    this->hightlightPositionVector = posToDrawIn;
    this->seeingRange = seeingRange;
}

float Seeing::getSeeingRange() const {
    return this->seeingRange;
}

