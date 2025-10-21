#include "raylib.h"
#include "player.h"
#include "fontloader.h"
#include "fontmanager.h"
#include "fonts.h"
#include <string>

Player player;

int main() {
    const int BASE_WIDTH = 1920;
    const int BASE_HEIGHT = 1080;

    const int monitor = GetCurrentMonitor();
    const int screenWidth = GetMonitorWidth(monitor);
    const int screenHeight = GetMonitorHeight(monitor);

    (void) screenWidth;
    (void) screenHeight;

    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(BASE_WIDTH, BASE_HEIGHT, "Pong Ping v1.0");

    SetTargetFPS(60);

    /*Font Definer*/
    FontManager::LoadFont("ShinGoProBold", "resources/fonts/ATTFShinGoProBold.ttf", 64);

    while (!WindowShouldClose()) {
        player.Update();

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        FontManager::DrawText("ShinGoProBold", "Test", 100, 200, 64, BLACK);
        player.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
