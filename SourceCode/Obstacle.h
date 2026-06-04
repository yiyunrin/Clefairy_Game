#pragma once
#include "raylib.h"
#include "Config.h"

class Obstacle{
private:
    Texture2D obsTextures[2];
    Rectangle rect;
    float speed;
    int currentType;
    bool scoreClaimed;
public:
    Obstacle(){
        obsTextures[0] = LoadTexture(Config::kapi_png[0]);
        obsTextures[1] = LoadTexture(Config::kapi_png[1]);
        Reset();
    }
    ~Obstacle(){
        UnloadTexture(obsTextures[0]);
        UnloadTexture(obsTextures[1]);
    }
    void Update(){
        rect.x -= speed;
        if(rect.x + rect.width < 0){
            Spawn();
            if(speed < Config::maxSpeed){
                speed *= Config::speedTimes;
            }
        }
    }
    void Draw(){
        Rectangle source = {0.0f, 0.0f, (float)obsTextures[currentType].width, (float)obsTextures[currentType].height};
        Vector2 origin = {0.0f, 0.0f};
        DrawTexturePro(obsTextures[currentType], source, rect, origin, 0.0f, WHITE);
    }
    void Spawn(){
        int randVal = GetRandomValue(1, 100);
        if(randVal <= 80){
            currentType = 0;
        }
        else{
            currentType = 1;
        }
        float tmpHeight = Config::kapi_heights[currentType];
        float oriWidth = (float)obsTextures[currentType].width;
        float oriHeight = (float)obsTextures[currentType].height;
        float tmpWidth = (oriWidth / oriHeight) * tmpHeight;
        rect.width = tmpWidth;
        rect.height = tmpHeight;
        rect.x = Config::screenWidth;
        rect.y = Config::groundHeight - tmpHeight;
        scoreClaimed = false;
    }
    void Reset(){
        speed = Config::initialSpeed;
        Spawn();
    }
    void CheckScore(float playerX, int &currentScore){
        if(!scoreClaimed && rect.x + rect.width < playerX){
            currentScore += Config::kapi_score[currentType];
            scoreClaimed = true;
        }
    }
    Rectangle GetRect(){
        return rect;
    }
};

