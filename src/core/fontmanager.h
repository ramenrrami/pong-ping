#pragma once

#include "raylib.h"
#include <string>
#include <unordered_map>

class FontManager{
    private:
    static std::unordered_map<std::string, Font> fonts;

    public:
    static void LoadFont(const std::string& name, const std::string& path, int fontSize = 32);
    static void UnloadAll();
    static void DrawText(const std::string& name, const std::string& text, float x, float y, float size, Color color);
    static Font* GetFont(const std::string& name);
};