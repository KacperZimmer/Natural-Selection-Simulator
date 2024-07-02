#define RAYGUI_IMPLEMENTATION

#include "../../include/SimulationInclude/Simulation.h"
#include <iostream>
#include "../../include/CreatureIncludes/creature.h"

#include "../../include/gui_lib/raygui.h"
#include "../../include/foodInclude/Food.h"
#include "../../include/foodInclude/foodContainer.h"
#include "../../include/EntityFactoryInclude/entityFactory.h"
#include "../../include/EntityFactoryInclude/creatureFactory.h"
#include "../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"



void Simulation::run() {
    FoodContainer foodContainer{};
    foodContainer.generateFood(100);

    std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();

    CreatureContainer creatureContainer{entityFactorytest};

    creatureContainer.generateSymmetricaly(1000,10.f);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Selection simulator");

    SetTargetFPS(60);
    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);

        creatureContainer.render();
        creatureContainer.update(foodContainer);

        if(GuiButton(Rectangle{0.f, SCREEN_HEIGHT - 50,120,50},"turn on vision")){

            creatureContainer.turnOnVision();

        }
        if(GuiButton(Rectangle{120, SCREEN_HEIGHT - 50,120,50},"turn off the vision")){

            creatureContainer.turnOffVision();

        }

        foodContainer.renderContainer();

        EndDrawing();
    }
}