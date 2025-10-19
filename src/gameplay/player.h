#pragma once
#include "raylib.h"

class Player{
    public:
    bool IsBoostReady() const { return canBoost; }

    Player();
    Rectangle GetHitbox() const { return hitbox; }

    void Update();
    void Draw();

    Vector2 position;

    private:
    Vector2 velocity;
    Vector2 acceleration;
    Rectangle hitbox;
    bool canBoost;
    float boostCoolDown;
    float boostTimer;
};