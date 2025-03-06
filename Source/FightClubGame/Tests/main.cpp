#include "Utils/Math.h"
#include "Game/Character.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace LifeEXEsimpoe;

TEST(Math, MaxShouldBeCalculatedCorrectly)
{
    ASSERT_TRUE(max(3, 0) == 3);
    ASSERT_TRUE(max(-3, 0) == 0);
}

TEST(Character, CharacterCanBeKilled)
{
    Character character("Nemo");
    ASSERT_TRUE(!character.isDead());

    character.takeDamage(10);
    ASSERT_TRUE(!character.isDead());

    character.takeDamage(1000);
    ASSERT_TRUE(character.isDead());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    const auto status = RUN_ALL_TESTS();
    std::cin.get();
    return status;
}
