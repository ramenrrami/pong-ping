#include "raylib.h"

int main(){
    const int monitor = GetCurrentMonitor();

    const int screenwidth = GetMonitorWidth(monitor);
    const int screenheight = GetMonitorHeight(monitor);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenwidth, screenheight, "Pong Ping");
    SetTargetFPS(60);

    MaximizeWindow();

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
        //== code ==//
    }
    CloseWindow();
    return 0;
}