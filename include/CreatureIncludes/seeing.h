
#ifndef EXAMPLE_SEEING_H
#define EXAMPLE_SEEING_H
#include <raylib.h>
#include <vector>
#include "../foodInclude/Food.h"
#include <memory>

class Seeing {
private:
    Vector2 hightlightPositionVector{};
    bool shouldDisplayVisionRange{false};
    float seeingRange;
    float closestDistance;
public:

    Seeing(const Vector2& posToDrawIn, float seeingRange);
    Seeing();

    int isFoodInRange(const std::vector<std::unique_ptr<Food>>& foodVector);
    bool ShouldDisplayVisionRange() const;
    void setHightlightPositionVector(const Vector2 &hightlightPositionVector);
    void setShouldDisplayVisionRange(bool shouldDisplayVisionRange);
    void highlightVisionRange();
    float getSeeingRange() const;

};


#endif //EXAMPLE_SEEING_H
