
#ifndef EXAMPLE_IOBSERVER_H
#define EXAMPLE_IOBSERVER_H


#include <cstddef>

class IObserver {

public:

    virtual void update(float velocity, float size, float seeingRadius, int day, size_t numfOfOrganisms) = 0;
};


#endif
