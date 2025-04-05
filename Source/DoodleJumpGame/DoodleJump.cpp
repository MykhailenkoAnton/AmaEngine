#include "DoodleJump.h"
#include "raylib.h"
#include "Types.h"
#include "Player.h"
#include "PlatformMananger.h"
#include "./Utils/Math.h"

namespace
{
constexpr ScreenSize c_screenSize{500, 700};

bool isOnPlarformGround(const Rectangle& player, const Rectangle& sweepPlayer, const Rectangle& platform, float yTreshold = 10.f)
{
    bool normalCollision = CheckCollisionRecs(player, platform);
    bool sweepCollision = CheckCollisionRecs(sweepPlayer, platform);

    return (normalCollision || sweepCollision) && (player.y + player.height - yTreshold <= platform.y);
}

}  // namespace

DoodleJump::DoodleJump()
{
    reset();
}

DoodleJump::~DoodleJump() {}

void DoodleJump::run()
{
    const char* windowTitle = "DoodleJump";
    InitWindow(c_screenSize.width, c_screenSize.height, "DoodleJump");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        SetWindowTitle(TextFormat("%s - %d FPS", windowTitle, GetFPS()));

        if (!m_isGameOver)
        {
            handleInput();
            update();
            draw();
        }
        else
        {
            if (IsKeyDown(KEY_ENTER))
            {
                reset();
            }

            drawGameOver();
        }
    }

    CloseWindow();
}

void DoodleJump::reset()
{
    m_isGameOver = false;
    m_score = 0;
    m_player.reset(new Player(c_screenSize));
    m_platformManager.reset(new PlatformManager(c_screenSize, LifeEXEsimpoe::randomFloat));
}

void DoodleJump::handleInput()
{
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        m_player->moveLeft(GetFrameTime());
    }

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        m_player->moveRight(GetFrameTime());
    }
}

void DoodleJump::update()
{
    m_player->update(GetFrameTime());

    if (m_player->velocityY() > 0.0f)
    {
        for (const auto& platform : m_platformManager->platforms())
        {
            if (isOnPlarformGround(m_player->aabb(), m_player->sweepAABB(), platform))
            {
                m_player->setY(platform.y - m_player->aabb().height);
                m_player->jump();
                break;
            }
        }
    }

    const float screenCenterY = c_screenSize.height * 0.5f;
    if (m_player->y() < screenCenterY - 50)
    {
        const float offsetY = (screenCenterY - 50) - m_player->y();
        m_player->setY(screenCenterY - 50);
        m_platformManager->applyScroll(offsetY);
        m_score += static_cast<int>(offsetY);
    }

    m_isGameOver = m_player->y() > c_screenSize.height;
}

void DoodleJump::draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (const auto& platform : m_platformManager->platforms())
    {
        DrawRectangleRec(platform, WHITE);
    }

    // DrawRectangleRec(m_player->sweepAABB(), {255, 255, 255, 120});
    DrawRectangleRec(m_player->aabb(), {255, 171, 0, 255});
    DrawRectangleLinesEx(m_player->aabb(), 2, LIGHTGRAY);

    DrawText(TextFormat("Score: %d", m_score), 10, 10, 20, WHITE);
    EndDrawing();
}

void DoodleJump::drawGameOver()
{
    const char* gameOverText = "GAME OVER";
    const int gameOverTextWidth = MeasureText(gameOverText, 80);
    const int gameOverTextCenterX = (c_screenSize.width - gameOverTextWidth) / 2;

    const char* scoreText = TextFormat("Score: %d", m_score);
    const int scoreTextWidth = MeasureText(scoreText, 50);
    const int scoreTextCenterX = (c_screenSize.width - scoreTextWidth) / 2;

    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(gameOverText, gameOverTextCenterX, c_screenSize.height / 2 - 80, 80, WHITE);
    DrawText(scoreText, scoreTextCenterX, c_screenSize.height / 2 + 50, 50, WHITE);

    EndDrawing();
}
