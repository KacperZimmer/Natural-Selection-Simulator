#ifndef EXAMPLE_FOODCONTAINER_H
#define EXAMPLE_FOODCONTAINER_H
#include <vector>
#include "Food.h"
class FoodContainer {
private:
    std::vector<std::unique_ptr<Food>> foodVector{};

public:
    void generateFood(int quantity);
    std::vector<std::unique_ptr<Food>>& getFoodArray() ;
    const Vector2& getVectorAtIndex(int index);
    void renderContainer();
    void deleteFood(int x);
};


#endif //EXAMPLE_FOODCONTAINER_H
