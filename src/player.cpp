#include "player.h"

Player::Player(){
    position = { 165, GetScreenHeight() / 2.0f };
    velocity = { 0.0f, 0.0f};
    acceleration = { 0.0f, 0.0f};
    hitbox = { position.x, position.y, 45, 245 };

    //boost timeout system
    canBoost = true;
    boostCoolDown = 0.8f;
    boostTimer = 0.0f;
}
void Player::Update(){
    //defined noraml & boost acceleration || disable boost on time-out
    float accelPower = 2.00f;
    if (IsKeyPressed(KEY_LEFT_SHIFT) && canBoost){
        accelPower = 58.0f;
        canBoost = false;
    }
    acceleration = {0.0f, 0.0f};

    //normal Keyinput
    if (IsKeyDown(KEY_W)) acceleration.y = -accelPower;
    if (IsKeyDown(KEY_S)) acceleration.y = accelPower;

    velocity.y += acceleration.y;
    velocity.y *= 0.9f;

    //position & hitbox updater
    position.y += velocity.y;
    hitbox.y = position.y;

    //boost timeout/cooldown
    if (!canBoost) {
        boostTimer += GetFrameTime();
        if (boostTimer >= boostCoolDown){
            canBoost = true;
            boostTimer = 0.0f;
        }
    }

    //screencorner barrier
    if (position.y < 0){
        position.y = 0;
        velocity.y = 0;
    }

    if (position.y + hitbox.height > GetScreenHeight()){
        position.y = GetScreenHeight() - hitbox.height;
        velocity.y = 0;
    }
}

void Player::Draw(){
    DrawRectangleRec(hitbox, DARKGRAY); 
    DrawText(TextFormat("Boost ready: %s", canBoost ? "YES" : "NO"), 10, 10, 20, BLACK);

}