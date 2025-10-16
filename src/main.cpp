#include "raylib.h"
#include "menu.hpp"

int main() {
    InitWindow(1280, 720, "Pong Ping");
    SetTargetFPS(60);

    RunMenu();

    CloseWindow();
    return 0;
}
