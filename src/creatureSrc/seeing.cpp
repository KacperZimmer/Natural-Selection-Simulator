
#include "../../include/CreatureIncludes/seeing.h"

#include <iostream>
#include "raymath.h"
void Seeing::highlightVisionRange() {

    if(this->shouldDisplayVisionRange){
        DrawCircle(this->hightlightPositionVector.x, this->hightlightPositionVector.y, 30.f, Color{25, 102, 209,125});
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

bool Seeing::isFoodInRange(const std::vector<std::unique_ptr<Food>> &foodVector) {
    for(const auto& i : foodVector){

        if(Vector2Distance(i->getPosition(), this->hightlightPositionVector) <= 0 + this->seeingRange + i->getFoodRadius()){
            return true;
        }
    }
    return false;
}

