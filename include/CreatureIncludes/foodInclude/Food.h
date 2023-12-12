

#ifndef EXAMPLE_FOOD_H
#define EXAMPLE_FOOD_H
#include "raylib.h"

class Food {

private:
    Vector2 position{};
    float foodRadius{1.f};
    float xPos{};
    float yPos{};

    float generateXrandomCoord();
    float generateYrandomCoord();

public:
    Food();
    Food(float foodRadius);
    const Vector2& getPosition() const;
    float getFoodRadius(){
        return this->foodRadius;
    }
    void render();

};


#endif //EXAMPLE_FOOD_H
