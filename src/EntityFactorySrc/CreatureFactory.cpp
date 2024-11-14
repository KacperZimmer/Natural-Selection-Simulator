
#include "../../include/EntityFactoryInclude/creatureFactory.h"

std::unique_ptr<Creature> CreatureFactory::prepareOne(float xPos, float yPos, float size, float speed, float seeingRange) {

    std::unique_ptr<Creature> creature = std::make_unique<Creature>(Vector2{xPos,yPos},size, speed, seeingRange);
    std::unique_ptr<Movable> movement = std::make_unique<Movement>(size, speed);



    movement->setInitialCreaturePosVector(xPos, yPos);
    Seeing seeing{movement->getPosition(), seeingRange};

    creature->setMovement((movement));
    creature->setSeeing(seeing);


    return creature;
}

std::unique_ptr<Creature>
CreatureFactory::makeChild(const Genome& parentGenome, const Vector2 coord) {

    std::unique_ptr<Creature> creature = std::make_unique<Creature>(

            Vector2{coord.x,coord.y}
    ,parentGenome.getSize(),
    parentGenome.getVelocity(),
    parentGenome.getSeeingRadius(),
    parentGenome.getRelativeSpeedFact()

    );

    creature->getGenome().generateGenome(parentGenome);

    std::unique_ptr<Movable> movement = std::make_unique<Movement>(creature->getGenome().getSize(),creature->getGenome().getVelocity() );

    movement->setInitialCreaturePosVector(coord.x, coord.y);
    Seeing seeing{movement->getPosition(), creature->getGenome().getSeeingRadius()};

    creature->setMovement((movement));
    creature->setSeeing(seeing);

    return creature;
}

