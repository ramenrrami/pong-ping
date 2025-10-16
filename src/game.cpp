#include "game.hpp"
#include "menu.hpp"

void RunGame() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        DrawText("GAME SCENE - Press ESC to return", 250, 300, 30, DARKGRAY);

        if (IsKeyPressed(KEY_ESCAPE)) {
            RunMenu(); // Zurück ins Menü
            break;
        }

        EndDrawing();
    }
}
