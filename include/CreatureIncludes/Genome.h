#include "raylib.h"


#ifndef EXAMPLE_GENOME_H
#define EXAMPLE_GENOME_H


class Genome {
private:
    float velocity{};
    float size{};
    float seeingRadius{};
    double energy{1};
    short relativeSpeedFact{};


public:
    Genome(float velocity, float radius, double energy, float sizeRadius, short relativeSpeed);


    Genome();

    void generateGenome(const Genome& genome);

    bool shouldGeneMutate() const;
    void mutateTheGenom();
    //getters
    float getSize() const;
    double getEnergy() const;
    float getVelocity() const;
    float getSeeingRadius() const;

    short getRelativeSpeedFact() const;

    void setRelativeSpeedFact(short relativeSpeedFact);

    //setters
    void setSize(float size);
    void setEnergy(double energy);
    void setVelocity(float velocity);
    void setSeeingRadius(float seeingRadius);

    ~Genome();
};


#endif //EXAMPLE_GENOME_H
