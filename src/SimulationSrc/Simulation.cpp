#define RAYGUI_IMPLEMENTATION

#include "../../include/SimulationInclude/Simulation.h"
#include "../../include/CreatureIncludes/creature.h"
#include <iostream>
#include <fstream>
#include <iomanip>

#include "../../include/gui_lib/raygui.h"
#include "../../include/EntityFactoryInclude/entityFactory.h"
#include "../../include/EntityFactoryInclude/creatureFactory.h"
#include "../../include/CreatureIncludes/creatureContainer/CreatureContainer.h"

void Simulation::run() {
    int creatureCount   = 24;
    int foodCount       = 50;
    int organismSize    = 20;
    int visionRange     = 100;
    int speed           = 2;
    bool inMenu         = true;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Selection simulator");
    SetTargetFPS(1000);

    static char saveFilePath[512] = "";
    bool exitRequested   = false;
    bool showSavePrompt  = false;

    while (!WindowShouldClose()) {
        if (inMenu) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Ustawienia symulacji", SCREEN_WIDTH/2 - 100, 50, 20, DARKGRAY);
            GuiSpinner({SCREEN_WIDTH/2 - 60, 100, 120, 30}, "Stworzenia:",      &creatureCount, 1, 100, false);
            GuiSpinner({SCREEN_WIDTH/2 - 60, 150, 120, 30}, "Jedzenie:",        &foodCount,     1, 300, false);
            GuiSpinner({SCREEN_WIDTH/2 - 60, 200, 120, 30}, "Organizm (px):",   &organismSize,  1, 10,  false);
            GuiSpinner({SCREEN_WIDTH/2 - 60, 250, 120, 30}, "Zasieg (px):",     &visionRange,   10, 50,  false);
            GuiSpinner({SCREEN_WIDTH/2 - 60, 300, 120, 30}, "Predkosc:",        &speed,         1, 10,  false);

            if (GuiButton({SCREEN_WIDTH/2 - 60, 360, 120, 40}, "Start")) {
                inMenu = false;
            }

            EndDrawing();
        }
        else {
            FoodContainer foodContainer{foodCount};
            foodContainer.generateFood(foodCount);


    std::unique_ptr<entityFactory> entityFactorytest = std::make_unique<CreatureFactory>();
    CreatureContainer creatureContainer{
            entityFactorytest,
            static_cast<float>(organismSize),
            static_cast<float>(visionRange),
            static_cast<float>(speed)
    };
            creatureContainer.generateCentre(creatureCount, organismSize);

            while (!WindowShouldClose() && !exitRequested) {
                BeginDrawing();
                ClearBackground(WHITE);

                creatureContainer.render();
                creatureContainer.update(foodContainer);

                if (GuiButton({0, SCREEN_HEIGHT - 50, 120, 50},   "Pokaz promien"))
                    creatureContainer.turnOnVision();
                if (GuiButton({120, SCREEN_HEIGHT - 50, 120, 50}, "wylacz promien"))
                    creatureContainer.turnOffVision();
                if (GuiButton({240, SCREEN_HEIGHT - 50, 120, 50}, "przyspiesz"))
                    creatureContainer.inreaseRelativeSpeed();
                if (GuiButton({360, SCREEN_HEIGHT - 50, 120, 50}, "zwolnij"))
                    creatureContainer.slowDownRelativeSpeed();

                if (!showSavePrompt && GuiButton({480, SCREEN_HEIGHT - 50, 160, 50}, "Zapisz")) {
                    showSavePrompt = true;
                    saveFilePath[0] = '\0';
                }

                if (showSavePrompt) {
                    const int boxW = 400, boxH = 180;
                    const int boxX = SCREEN_WIDTH/2 - boxW/2;
                    const int boxY = SCREEN_HEIGHT/2 - boxH/2;
                    DrawRectangle(boxX, boxY, boxW, boxH, Fade(GRAY, 0.8f));

                    GuiLabel({boxX + 20, boxY + 20, 100, 20}, "Zapisz Sciezke");
                    GuiTextBox({boxX + 20, boxY + 50, boxW - 40, 30},
                               saveFilePath, sizeof(saveFilePath), true);

                    if (GuiButton({boxX + 20, boxY + 100, 160, 40}, "Potwierdz")) {
                        exitRequested = true;
                    }
                    if (GuiButton({boxX + boxW - 180, boxY + 100, 160, 40}, "Anuluj")) {
                        showSavePrompt = false;
                    }
                }

                foodContainer.renderContainer();
                EndDrawing();
            }

            CloseWindow();

            std::ofstream out(saveFilePath, std::ios::trunc);
            if (!out) {
                std::cerr << "Błąd otwarcia pliku: " << saveFilePath << "\n";
            } else {
                out << std::left
                    << std::setw(10) << "Dzien"
                    << std::setw(15) << "AvgSize"
                    << std::setw(15) << "AvgVel"
                    << std::setw(18) << "AvgSeeingRange"
                    << "\n";

                auto dm    = creatureContainer.getDataHub();
                auto& hist = dm->getHistory();
                for (const auto& d : hist) {
                    out << std::left
                        << std::setw(10) << d.day
                        << std::setw(15) << d.avgSizePerDay
                        << std::setw(15) << d.avgVelPerDay
                        << std::setw(18) << d.avgSeeingRangePerDay
                        << "\n";
                }

                out.close();
                std::cout << "Zapisano historię do: " << saveFilePath << "\n";
            }

            return;
        }
    }

    CloseWindow();
}
