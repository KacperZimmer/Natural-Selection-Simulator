
#ifndef EXAMPLE_SEEING_H
#define EXAMPLE_SEEING_H
#include <raylib.h>



class Seeing {
private:
    Vector2 hightlightPositionVector{};
    bool shouldDisplayVisionRange{false};
    float seeingRange{20.f};
public:
    Seeing(const Vector2& posToDrawIn){
        this->hightlightPositionVector = posToDrawIn;
    }

    void setHightlightPositionVector(const Vector2 &hightlightPositionVector);
    void setShouldDisplayVisionRange(bool shouldDisplayVisionRange);

    void highlightVisionRange();
    bool ShouldDisplayVisionRange() const;

};


#endif //EXAMPLE_SEEING_H