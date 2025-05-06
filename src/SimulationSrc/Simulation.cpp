#define RAYGUI_IMPLEMENTATION

#include "../../include/SimulationInclude/Simulation.h"
#include "../../include/CreatureIncludes/creature.h"
#include <iostream>
#include "../../include/gui_lib/raygui.h"
#include "../../include/EntityFactoryInclude/entityFactory.h"
#include "../../include/EntityFactoryInclude/creatureFactory.h"
#include "../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"

void Simulation::run() {

    int creatureCount   = 24;
    int foodCount       = 50;
    int organismSize    = 20;    // wielkość organizmu
    int visionRange     = 100;   // zasięg widzenia
    int speed           = 2;     // prędkość
    bool inMenu         = true;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Selection simulator");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (inMenu) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Ustawienia symulacji", SCREEN_WIDTH / 2 - 100, 50, 20, DARKGRAY);

            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 100, 120, 30}, "Stworzenia:",   &creatureCount, 1,   100, false);
            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 150, 120, 30}, "Jedzenie:",     &foodCount,     1,   300, false);

            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 200, 120, 30}, "Organizm (px):",&organismSize, 1,   10,  false);
            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 250, 120, 30}, "Zasieg (px):",  &visionRange,  10,  50, false);
            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 300, 120, 30}, "Prędkość:",     &speed,         1,   10,  false);

            if (GuiButton(Rectangle{SCREEN_WIDTH / 2 - 60, 360, 120, 40}, "Start")) {
                inMenu = false;
            }

            EndDrawing();
        } else {
            FoodContainer foodContainer{foodCount};
            foodContainer.generateFood(foodCount);
            std::cout << organismSize << std::endl;

            std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();
            CreatureContainer creatureContainer{
                    entityFactorytest,
                    static_cast<float>(organismSize),
                    static_cast<float>(visionRange),
                    static_cast<float>(speed)
            };

            creatureContainer.generateSymmetricaly(creatureCount, organismSize);

            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(WHITE);

                creatureContainer.render();
                creatureContainer.update(foodContainer);

                if (GuiButton(Rectangle{0.f, SCREEN_HEIGHT - 50, 120, 50}, "turn on vision")) {
                    creatureContainer.turnOnVision();
                }
                if (GuiButton(Rectangle{120, SCREEN_HEIGHT - 50, 120, 50}, "turn off the vision")) {
                    creatureContainer.turnOffVision();
                }
                if (GuiButton(Rectangle{240, SCREEN_HEIGHT - 50, 120, 50}, "speed up")) {
                    creatureContainer.inreaseRelativeSpeed();
                }
                if (GuiButton(Rectangle{360, SCREEN_HEIGHT - 50, 120, 50}, "slow down")) {
                    creatureContainer.slowDownRelativeSpeed();
                }

                foodContainer.renderContainer();
                EndDrawing();
            }
        }
    }

    CloseWindow();
}
