#pragma once

#include "raylib.h"

#include "Types.h"

class Player
{
public:
    struct Config
    {
        float width;
        float height;
        float speed;
        float gravity;
        float jumpVelocityY;
        float initialOffsetY;

        Config() : width(40.0f), height(40.0f), speed(210.0f), gravity(400.0f), jumpVelocityY(-500.0f), initialOffsetY(-50.f) {}
    };

    Player(const ScreenSize& screenSize, const Config& config = Config());

    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
    void update(float deltaTime);
    void jump();

    void setY(float y);

    float y() const;
    float velocityY() const;
    Rectangle aabb() const;
    Rectangle sweepAABB() const;

private:
    const ScreenSize c_screenSize;
    const Config c_config;

    float m_x;
    float m_y;
    float m_previousY;
    float m_velocityY;
};