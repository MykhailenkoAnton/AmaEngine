
#include "Utils/Math.h"
#include "Character.h"
#include "Weapon.h"
#include <iostream>

Character::Character(const char* name) : m_name(name)
{
    const int bullets = LifeEXEsimpoe::randomInt(1, 10);
    m_weapon = new Weapon(bullets);
}

Character::~Character()
{
    delete m_weapon;
    m_weapon = nullptr;
}

const char* Character::name() const
{
    return m_name;
}

bool Character::isDead() const
{
    return m_health == 0;
}

bool Character::attack(Character& character)
{
    const bool fired = m_weapon->fire();
    if (fired)
    {
        const int damage = m_weapon->damage();
        std::cout << m_name << " is attacking with damage " << damage << std::endl;
        character.takeDamage(damage);
    }
    else
    {
        std::cout << m_name << " has no more bullets..." << std::endl;
    }

    return fired;
}

void Character::takeDamage(int damage)
{
    m_health -= damage;
    if (m_health < 0)
    {
        m_health = 0;
    }

    std::cout << m_name << " was attacked, current health " << m_health << std::endl;
}
