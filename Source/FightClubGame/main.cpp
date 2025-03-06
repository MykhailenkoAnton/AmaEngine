
#include "Game/Character.h"
#include "Utils/Math.h"
#include <iostream>
#include <thread>

int main()
{
#ifdef SKIP_GAME
    std::cout << " ===========  NO GAME AVAILABLE!!!! ==========" << std::endl;
    return 0;
#endif  // SKIP_GAME

    Character character1("Tor");
    Character character2("Ronald");

    Character* attacker = &character1;
    Character* defender = &character2;

    bool lastFireStatus = true;

    int roundNum = 1;
    while (true)
    {
        std::cout << " =========== ROUND ============== " << roundNum++ << " ===================" << std::endl;

        const bool fired = attacker->attack(*defender);
        if (lastFireStatus == fired && !fired)
        {
            std::cout << std::endl;
            std::cout << " =========== GAME OVER ==============" << std::endl;
            std::cout << " Friendship WINS!" << std::endl;
            break;
        }

        lastFireStatus = fired;

        if (defender->isDead())
        {
            std::cout << std::endl;
            std::cout << " =========== GAME OVER ==============" << std::endl;
            std::cout << defender->name() << " is dead..." << std::endl;
            std::cout << attacker->name() << " WINS " << std::endl;
            break;
        }

        std::swap(attacker, defender);
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // std::cin.get();

    return 0;
}
