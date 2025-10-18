#pragma once

#include "raylib.h"
#include <string>

class FontLoader {
    private:
    static Font font;
    static bool loaded;

    public:
    static void Load(const std::string& fontPath, int fontSize = 32);
    static void Unload();
    static void DrawText(const std::string& text, float x, float y, float fontSize, Color color);
};