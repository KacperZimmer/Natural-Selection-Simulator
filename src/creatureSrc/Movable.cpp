
#include <cfloat>
#include "../../include/CreatureIncludes/Movable.h"
#include "../../include/constantValues.h"
#include <raymath.h>


Movable::~Movable() {

}

void Movable::goBackToLegalPositionIfOutOfBound() {

    auto isNotInBounds = [this](){

        return this->currentPosition.x >= SCREEN_WIDTH - this->creatureRadius
        || this->currentPosition.x <= 0 + this->creatureRadius ||
        this->currentPosition.y >= SCREEN_HEIGHT - this->creatureRadius ||
        this->currentPosition.y <= 0 + this->creatureRadius;
    };

    if(!isNotInBounds()){
        this->lastLegalPosition = currentPosition;
    }else{
        this->currentPosition = lastLegalPosition;
    }
}

const Vector2 &Movable::getPosition() const {
    return this->currentPosition;
}

Vector2 Movable::getClosestPathToBoundaryVector() const {

    Vector2 closestPoint{};

    float shortestPath = FLT_MAX;
    float current_x_pos = this->creatureRadius, current_y_pos = this->creatureRadius;

    float y_spacing = 1;
    float x_spacing = 1;

    for(short i = 0; i < 4; i++){
        for(int j = 0; j < SCREEN_WIDTH - this->creatureRadius * 2; ++j){

            Vector2 currentPositionToCheck{current_x_pos, current_y_pos};

            float distanceToTheGivenPoint = Vector2Distance(this->currentPosition,currentPositionToCheck);

            if(shortestPath > distanceToTheGivenPoint){
                closestPoint.x = current_x_pos;
                closestPoint.y = current_y_pos;
                shortestPath = distanceToTheGivenPoint;
            }

            switch (i){
                case 0:
                    current_x_pos += x_spacing;
                    break;

                case 1:
                    current_y_pos += y_spacing;
                    break;

                case 2:
                    current_x_pos -= x_spacing;
                    break;

                case 3:
                    current_y_pos -= y_spacing;
                    break;

                default:
                    break;
            }
        }
    }
    return closestPoint;
}

void Movable::setInitialCreaturePosVector(float x, float y) {
    this->currentPosition.x = x;
    this->currentPosition.y = y;
}

Movable::Movable(float creatureRadius, float speed) : creatureRadius(creatureRadius), speed(speed) {}

void Movable::setRelativeSpeedFactor(short relativeSpeedFactor) {
    this->relativeSpeedFactor = relativeSpeedFactor;
}
