
#ifndef EXAMPLE_MOVEMENT_H
#define EXAMPLE_MOVEMENT_H
#include "../constantValues.h"
#include "../../include/constantValues.h"
#include "raylib.h"
#include "Movable.h"
#include <vector>
#include <random>

class Movement : public Movable{
private:
    float shouldUpdatePosition{};
    float deltaTime{};
    float timeAfterPositionShouldBeUpdated{1.f/1.3f};
    int xDirection{1};
    int yDirection{1};
    int generateRandomDirection() const;


public:

    Movement(float creatureRadius, float speed);
    void move() override;
    void goToTarget(const Vector2& target) override;
    bool checkIfTargetIsReached(Vector2 target) override;



};


#endif //EXAMPLE_MOVEMENT_H
