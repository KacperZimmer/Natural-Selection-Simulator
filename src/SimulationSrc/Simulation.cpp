#define RAYGUI_IMPLEMENTATION

#include "../../include/SimulationInclude/Simulation.h"
#include "../../include/CreatureIncludes/creature.h"
#include "../../include/gui_lib/raygui.h"
#include "../../include/EntityFactoryInclude/entityFactory.h"
#include "../../include/EntityFactoryInclude/creatureFactory.h"
#include "../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"

void Simulation::run() {

    int creatureCount = 24;
    int foodCount = 50;
    bool inMenu = true;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Selection simulator");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (inMenu) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Ustawienia symulacji", SCREEN_WIDTH / 2 - 100, 50, 20, DARKGRAY);

            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 100, 120, 30}, "Stworzenia:", &creatureCount, 1, 100, true);
            GuiSpinner(Rectangle{SCREEN_WIDTH / 2 - 60, 150, 120, 30}, "Jedzenie:", &foodCount, 1, 100, true);

            if (GuiButton(Rectangle{SCREEN_WIDTH / 2 - 60, 200, 120, 40}, "Start")) {
                inMenu = false;
            }

            EndDrawing();
        } else {
            FoodContainer foodContainer{};
            foodContainer.generateFood(foodCount);

            std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();
            CreatureContainer creatureContainer{entityFactorytest};

            creatureContainer.generateSymmetricaly(creatureCount, 10.f);

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
