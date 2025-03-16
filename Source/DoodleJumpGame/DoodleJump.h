#pragma once

#include <memory>

class Player;
class PlatformManager;

class DoodleJump
{
public:

	DoodleJump();

    ~DoodleJump();
    void run();

private:

    void reset();

    void handleInput();

    void update();

    void draw();

    void drawGameOver();

private:

    bool m_isGameOver;
    int m_score;

    std::unique_ptr<Player> m_player;
    std::unique_ptr<PlatformManager> m_platformManager;
};