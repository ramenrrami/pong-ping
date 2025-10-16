#include "menu.hpp"
#include "game.hpp"
#include <vector>
#include <string>

void RunMenu() {
    int selected = 0;
    std::vector<std::string> options = { "Start Game", "Exit" };

    while (!WindowShouldClose()) {
        // Steuerung
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) selected--;
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) selected++;
        if (selected < 0) selected = options.size() - 1;
        if (selected >= options.size()) selected = 0;

        // Auswahl
        if (IsKeyPressed(KEY_ENTER)) {
            if (selected == 0) {
                RunGame(); // Spiel starten
            } else if (selected == 1) {
                break; // Beenden
            }
        }

        // Zeichnen
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("=== PONG PING ===", 420, 150, 50, DARKGRAY);

        for (int i = 0; i < options.size(); i++) {
            Color color = (i == selected) ? ORANGE : GRAY;
            int width = MeasureText(options[i].c_str(), 40);
            DrawText(options[i].c_str(),
                     GetScreenWidth() / 2 - width / 2,
                     350 + i * 80,
                     40,
                     color);
        }

        DrawText("Use W/S or ↑/↓ to move, Enter to select",
                 GetScreenWidth() / 2 - 250, 600, 20, LIGHTGRAY);

        EndDrawing();
    }
}
