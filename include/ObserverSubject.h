

#ifndef EXAMPLE_OBSERVERSUBJECT_H
#define EXAMPLE_OBSERVERSUBJECT_H

#include <memory>
#include <vector>
#include <algorithm>
#include "IObserver.h"

class ObserverSubject {

private:

    std::vector<std::shared_ptr<IObserver>> observers{};

public:

    void addObserver(const std::shared_ptr<IObserver>& observer){
        observers.push_back(observer);
    }

    void notify(float velocity, float size, float seeingRadius, int day){

        for(auto& observer: this->observers){

            observer->update(velocity,size,seeingRadius,day);
        }
    }

};


#endif
