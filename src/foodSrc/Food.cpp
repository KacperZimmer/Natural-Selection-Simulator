#include <random>
#include "../../include/foodInclude/Food.h"
#include "../../include/constantValues.h"

std::random_device rd;
std::mt19937 gen(rd());

Food::Food(float foodRadius) {
    this->foodRadius = foodRadius;
    this->position.x = this->generateXrandomCoord();
    this->position.y = this->generateYrandomCoord();

}

const Vector2 &Food::getPosition() const{
    return this->position;
}



Food::Food() {
}

void Food::render() {
    DrawCircle(static_cast<int>(this->position.x), static_cast<int>(this->position.y), this->foodRadius, GREEN);
}

float Food::generateXrandomCoord() {

    std::uniform_real_distribution<float> dis(0.0f, static_cast<float>(SCREEN_WIDTH));

    return dis(gen);
}

float Food::generateYrandomCoord() {

    std::uniform_real_distribution<float> dis(0.0f, static_cast<float>(SCREEN_WIDTH));

    return dis(gen);
}

