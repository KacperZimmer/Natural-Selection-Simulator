
#ifndef EXAMPLE_IOBSERVER_H
#define EXAMPLE_IOBSERVER_H


class IObserver {

public:

    virtual void update(float velocity, float size, float seeingRadius, int day) = 0;
};


#endif
