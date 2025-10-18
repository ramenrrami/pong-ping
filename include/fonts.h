#pragma once
#include "fontmanager.h"

//define Fonts
inline void ShinGoProBold(const std::string& text, float x, float y, float size, Color color) {
    FontManager::DrawText("ShinGoPro", text, x, y, size, color);
}
