#pragma once
#include "raylib.h"
#include "Config.h"
#include "InputManager.h"

class Player{
private:
    Texture2D runTextures[2];
    Rectangle rect;
    float velocityY;
    int jumpCount;
    int currentFrame;
    int frameCounter;
public:
    Player(){
        runTextures[0] = LoadTexture(Config::pipi_png[0]);
        runTextures[1] = LoadTexture(Config::pipi_png[1]);
        Reset();
    }
    ~Player() {
        UnloadTexture(runTextures[0]);
        UnloadTexture(runTextures[1]);
    }
    void Update(){
        frameCounter += 1;
        if(frameCounter >= 10){
            currentFrame = 1 - currentFrame;
            frameCounter = 0;
        }
        if(InputManager::IsActionPressed(GameAction::JUMP) && jumpCount < 2){
            velocityY = Config::jumpForce;
            jumpCount += 1;
        }
        velocityY += Config::gravity;
        rect.y += velocityY;
        if(rect.y >= Config::groundHeight - rect.height){
            rect.y = Config::groundHeight - rect.height;
            velocityY = 0.0f;
            jumpCount = 0;
        }
    }
    void Draw(){
        Rectangle source = {0.0f, 0.0f, (float)runTextures[currentFrame].width, (float)runTextures[currentFrame].height};
        Vector2 origin = {0.0f, 0.0f};
        DrawTexturePro(runTextures[currentFrame], source, rect, origin, 0.0f, WHITE);
    }
    void Reset(){
        rect = {100, 300, 40, 40};
        velocityY = 0.0f;
        currentFrame = 0;
        frameCounter = 0;
    }
    Rectangle GetRect() const{
        return rect;
    }
};