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
