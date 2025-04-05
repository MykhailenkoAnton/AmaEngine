#include "gtest/gtest.h"
#include "Types.h"
#include "Player.h"
#include "PlatformMananger.h"

namespace
{
int randomFuncIndex = 0;
float mockRandomFuncFromArray(float min = 0.0f, float max = 0.0f)
{
    std::vector<float> randomValues = {10.f, 20.f, 30.f, 40.f, 50.f, 60.f, 70.f, 80.f, 90.f, 100.f};
    return randomValues[(randomFuncIndex++) % randomValues.size()];
}
}  // namespace

TEST(PlayerTest, JumpVelocityShouldBeSetCorrectly)
{
    const ScreenSize screenSize{500, 700};
    Player::Config config;
    config.jumpVelocityY = 913.f;

    Player player{screenSize, config};

    if (player.velocityY() == 0)
    {
        player.jump();
        ASSERT_EQ(player.velocityY(), config.jumpVelocityY);
    }
}

TEST(PlayerTest, PlayerShouldFallUnderTheGravity)
{
    const ScreenSize screenSize{500, 700};
    Player::Config config;
    Player player{screenSize, config};

    player.update(1.0f);

    const float initialY = screenSize.height * 0.5f - config.initialOffsetY;
    ASSERT_EQ(player.y(), initialY + config.gravity);
}

TEST(PlatformManagerTest, PlarformPositionShouldBeSetCorecctly)
{
    const ScreenSize screenSize{500, 700};
    PlatformManager platformManager(screenSize, mockRandomFuncFromArray);

    const float platformCount = 10;
    const auto platforms = platformManager.platforms();
    ASSERT_EQ(platforms.size(), platformCount);

    randomFuncIndex = 0;
    const float verticalSpacing = static_cast<float>(screenSize.height) / platformCount;
    for (int i = 0; i < platforms.size(); ++i)
    {
        const float expectedX = mockRandomFuncFromArray();
        const float expectedY = i * verticalSpacing + mockRandomFuncFromArray();

        EXPECT_NEAR(platforms[i].x, expectedX, 0.001f);
        EXPECT_NEAR(platforms[i].y, expectedY, 0.001f);
    }
}
