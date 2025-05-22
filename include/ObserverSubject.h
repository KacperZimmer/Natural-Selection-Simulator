

#ifndef EXAMPLE_OBSERVERSUBJECT_H
#define EXAMPLE_OBSERVERSUBJECT_H

#include <memory>
#include <vector>
#include <algorithm>
#include "IObserver.h"

class ObserverSubject {

private:


public:
    std::vector<std::shared_ptr<IObserver>> observers{};

    void addObserver(const std::shared_ptr<IObserver>& observer){
        observers.push_back(observer);
    }

    void notify(float velocity, float size, float seeingRadius, int day, size_t numOfOrganisms){

        for(auto& observer: this->observers){

            observer->update(velocity,size,seeingRadius,day, numOfOrganisms);
        }
    }

};


#endif
