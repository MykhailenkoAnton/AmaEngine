#include <cassert>
#include "Utils/Math.h"
#include "Game/Character.h"

int main()
{
    using namespace LifeEXEsimpoe;
    assert(max(3, 0) == 3);
    assert(max(-3, 0) == 0);

    Character character("Nemo");
    assert(!character.isDead());

    character.takeDamage(10);
    assert(!character.isDead());

    character.takeDamage(10000);
    assert(character.isDead());

    return 0;
}