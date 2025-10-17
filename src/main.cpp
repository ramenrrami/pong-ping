#include "raylib.h"
#include "player.h"

Player player;

int main() {
    const int monitor = GetCurrentMonitor();
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Pong Ping v1.0");
    SetTargetFPS(60);

    int monitorWidth = GetMonitorWidth(monitor);
    int monitorHeight = GetMonitorHeight(monitor);

    int posX = (monitorWidth - screenWidth) / 2;
    int posY = (monitorHeight - screenHeight) / 2;

    SetWindowPosition(posX, posY);

    while (!WindowShouldClose()) {
        player.Update();

        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        player.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
