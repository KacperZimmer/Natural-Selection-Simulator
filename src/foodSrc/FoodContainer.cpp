
#include "../../include/foodInclude/foodContainer.h"
#include <stdexcept>
void FoodContainer::generateFood(int quantity) {

    if(this->foodNum == -1){
        this->foodNum = quantity;
    }else{
        this->foodNum += quantity;
    }
    for(size_t i = 0; i < quantity; ++i){
        this->foodVector.emplace_back(std::make_unique<Food>(10));
    }
}

std::vector<std::unique_ptr<Food>> &FoodContainer::getFoodArray(){

    return this->foodVector;
}
void FoodContainer::renderContainer() {

    for(const auto& food : this->foodVector){
        if(food != nullptr){food->render();}
    }
}

void FoodContainer::deleteFood(int x) {


    std::unique_ptr<Food>& foodToDelete = this->foodVector[x];
    if(foodToDelete != nullptr){foodToDelete.reset();}
    --this->foodNum;
}

const Vector2 &FoodContainer::getVectorAtIndex(int index) {

    if (index >= 0 && index < foodVector.size()) {
        return this->foodVector[index]->getPosition();
    } else {
        throw std::out_of_range("Index out of range");
    }

}

size_t FoodContainer::containerSize() {

    return this->foodVector.size();
}

int FoodContainer::getFoodNum() const {
    return foodNum;
}

FoodContainer::FoodContainer(int numOfFoodToGenerate) : numOfFoodToGenerate(numOfFoodToGenerate) {
    this->numOfFoodToGenerate = numOfFoodToGenerate;
}

int FoodContainer::getNumOfFoodToGenerate() const {
    return numOfFoodToGenerate;
}


