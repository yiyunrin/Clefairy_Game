#pragma once

namespace Config{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float gravity = 0.8f;
    const float jumpForce = -12.0f;
    const float groundHeight = 380;

    inline constexpr const char* pipi_png[2] = {"pipi_run1.png", "pipi_run2.png"};
    inline constexpr const char* kapi_png[2] = {"kapi1.png", "kapi2.png"};
    inline constexpr float kapi_heights[2] = {40.0f, 80.0f};
    inline constexpr int kapi_score[2] = {10, 20};


    const float initialSpeed = 6.0f;
    const float speedTimes = 1.02;
    const float maxSpeed = 20.0f;

    const char* overText = "GAME OVER";
    const int overSize = 40;

    const char* restartText = "Press ENTER to Restart";
    const int restartSize = 20;
}