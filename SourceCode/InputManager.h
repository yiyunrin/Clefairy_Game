#pragma once
#include "raylib.h"

enum class GameAction{
    JUMP,
    RESTART
};

class InputManager{
public:
    static bool IsActionPressed(GameAction action){
        switch (action){
            case GameAction::JUMP:
                return IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsGestureDetected(GESTURE_TAP);
            case GameAction::RESTART:
                return IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsGestureDetected(GESTURE_TAP);
            default:
                return false;
        }
    }
};