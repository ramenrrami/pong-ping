#include "fontloader.h"
#include <iostream>

Font FontLoader::font = { 0, 0, 0, {0}, nullptr, nullptr };
bool FontLoader::loaded = false;

void FontLoader::Load(const std::string& fontPath, int fontSize){
    if (loaded) return;

    font = LoadFontEx(fontPath.c_str(), fontSize, 0, 0);
    if (font.texture.id == 0){
        TraceLog(LOG_ERROR, "ERORR: Font could not Load");
    } else{
        TraceLog(LOG_INFO, "Font Could Load.");
    }

    loaded = true;
    std::cout << "Font Load: " << fontPath << std::endl;
}

void FontLoader::Unload(){
    if (loaded){
        UnloadFont(font);
        loaded = false;
        std::cout << "Font unload." << std::endl;
    }
}

void FontLoader::DrawText(const std::string& text, float x, float y, float fontSize, Color color){
    if (!loaded) {
        std::cerr << "Font isn't loaded yet!" << std::endl;
        return;
    }
    DrawTextEx(font, text.c_str(), {x, y}, fontSize, 2, color);
}