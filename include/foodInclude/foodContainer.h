#ifndef EXAMPLE_FOODCONTAINER_H
#define EXAMPLE_FOODCONTAINER_H
#include <vector>
#include "Food.h"
#include <memory>

class FoodContainer {
private:
    std::vector<std::unique_ptr<Food>> foodVector{};
    int foodNum{-1};
    int numOfFoodToGenerate{};

public:
    void generateFood(int quantity);
    std::vector<std::unique_ptr<Food>>& getFoodArray() ;
    const Vector2& getVectorAtIndex(int index);
    void renderContainer();
    void deleteFood(int x);
    size_t containerSize();
    explicit FoodContainer(int numOfFoodToGenerate);
    int getFoodNum() const;
    int getNumOfFoodToGenerate() const;
};


#endif //EXAMPLE_FOODCONTAINER_H
