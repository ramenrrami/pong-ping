#include "fontmanager.h"
#include <iostream>

std::unordered_map<std::string, Font> FontManager::fonts;

void FontManager::LoadFont(const std::string& name, const std::string& path, int fontSize){
    if (fonts.count(name)){
        std::cerr << "Font '" << name << "' is already loaded!\n";
        return;
    }
    Font font = LoadFontEx(path.c_str(), fontSize, 0, 0);
    if (font.texture.id == 0){
        std::cerr << "ERROR: could not font load: " << path << std::endl;
        return;
    }
    fonts[name] = font;
    std::cout << "Font '" << name << "' geladen.\n";
}

void FontManager::UnloadAll() {
    for (auto& [name, font] : fonts) {
        UnloadFont(font);
        std::cout << "Font '" << name << "' entladen.\n";
    }
    fonts.clear();
}

void FontManager::DrawText(const std::string& name, const std::string& text, float x, float y, float size, Color color) {
    if (!fonts.count(name)) {
        std::cerr << "Font '" << name << "' nicht gefunden!\n";
        return;
    }

    DrawTextEx(fonts[name], text.c_str(), {x, y}, size, 2, color);
}

Font* FontManager::GetFont(const std::string& name) {
    if (!fonts.count(name)) return nullptr;
    return &fonts[name];
}