#ifndef EXAMPLE_FOODCONTAINER_H
#define EXAMPLE_FOODCONTAINER_H
#include <vector>
#include "Food.h"
class FoodContainer {
private:
    std::vector<std::unique_ptr<Food>> foodVector{};
    int foodNum{-1};

public:
    void generateFood(int quantity);
    std::vector<std::unique_ptr<Food>>& getFoodArray() ;
    const Vector2& getVectorAtIndex(int index);
    void renderContainer();
    void deleteFood(int x);
    size_t containerSize();

    int getFoodNum() const;
};


#endif //EXAMPLE_FOODCONTAINER_H
