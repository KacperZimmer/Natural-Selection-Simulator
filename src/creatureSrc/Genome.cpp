
#include "../../include/CreatureIncludes/Genome.h"
#include <random>


void Genome::mutateTheGenom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> prp(1, 100);

    // Use a uniform distribution to generate factors between 0.5 and 1.5
    std::uniform_real_distribution<> dis(0.5, 1.5);

    double probability = prp(gen);
    float factor{};

    for (int i = 0; i < 3; ++i) {
        factor = dis(gen);
        if(factor < 0){

        }

        switch (i) {
            case 0:
                this->velocity *= factor;
                break;
            case 1:
                this->seeingRadius *= factor;
                break;
            case 2:
                this->size *= factor;
                break;
            default:
                break;
        }
    }
}

void Genome::generateGenome(const Genome &genome) {

    this->velocity = genome.getVelocity();
    this->energy = genome.getEnergy();
    this->seeingRadius = genome.getSeeingRadius();
    this->size = genome.getSize();

    if(shouldGeneMutate()){
        mutateTheGenom();
    }
}

bool Genome::shouldGeneMutate() const {


    std::random_device rd;

    std::mt19937  gen(rd());
    std::normal_distribution<> dis(1, 100);

    float probability = dis(gen);


    if(probability > 0 ) return true;
    return false;
}


Genome::Genome() {}

void Genome::setVelocity(float velocity) {
    Genome::velocity = velocity;
}


void Genome::setEnergy(double energy) {
    Genome::energy = energy;
}


void Genome::setSize(float size) {
    Genome::size = size;
}

void Genome::setSeeingRadius(float seeingRadius) {
    Genome::seeingRadius = seeingRadius;
}

float Genome::getSize() const {
    return size;
}

float Genome::getSeeingRadius() const {
    return seeingRadius;
}


float Genome::getVelocity() const {
    return velocity;
}

double Genome::getEnergy() const {
    return energy;
}
Genome::~Genome() {

}

Genome::Genome(float velocity, float radius, double energy, float sizeRadius, short relativeSpeed) {
    this->velocity = velocity;
    this->seeingRadius = radius;
    this->energy = energy;
    this->size = sizeRadius;
    this->relativeSpeedFact = relativeSpeed;
}

short Genome::getRelativeSpeedFact() const {
    return relativeSpeedFact;
}

void Genome::setRelativeSpeedFact(short relativeSpeedFact) {
    Genome::relativeSpeedFact = relativeSpeedFact;
}
