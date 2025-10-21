#include "raylib.h"
#include "rlgl.h"
#include "player.h"
#include "fontloader.h"
#include "fontmanager.h"
#include "fonts.h"

#include <string>
#include <cmath>
#include <algorithm>

Player player;

int main() {
    const int BASE_WIDTH = 1920;
    const int BASE_HEIGHT = 1080;

    //temporarely window
    InitWindow(1920, 1080, "Pong Ping v1.0");

    const int monitor = GetCurrentMonitor();
    const int screenWidth = GetMonitorWidth(monitor);
    const int screenHeight = GetMonitorHeight(monitor);

    CloseWindow();

    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Pong Ping v1.0");

    const float scaleX = (float)screenWidth / BASE_WIDTH;
    const float scaleY = (float)screenHeight / BASE_HEIGHT;
    const float scale = fminf(scaleX, scaleY);

    const float offsetX = (screenWidth - (BASE_WIDTH * scale)) / 2.0f;
    const float offsetY = (screenHeight - (BASE_HEIGHT * scale)) / 2.0f;

    (void) screenWidth;
    (void) screenHeight;

    SetTargetFPS(60);
    /*Font Definer*/
    FontManager::LoadFont("ShinGoProBold", "resources/fonts/ATTFShinGoProBold.ttf", 64);

    while (!WindowShouldClose()) {
        player.Update();
        BeginDrawing();
        ClearBackground(BLACK);

        rlPushMatrix();
        rlTranslatef(offsetX, offsetY, 0);
        rlScalef(scale, scale, 1);

        ClearBackground(LIGHTGRAY);
        FontManager::DrawText("ShinGoProBold", "Test", 100, 200, 64, BLACK);
        player.Draw();

        rlPopMatrix();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
