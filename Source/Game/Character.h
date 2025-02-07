#pragma once

#ifdef _EXPORTING
#define GAME_API __declspec(dllexport)
#elif _IMPORTING
#define GAME_API __declspec(dllimport)
#else
#define GAME_API
#endif

class Weapon;

class GAME_API Character
{
public:
    Character(const char* name);
    ~Character();

    const char* name() const;
    bool isDead() const;
    bool attack(Character& character);
    void takeDamage(int damage);

private:
    const char* m_name;
    Weapon* m_weapon;
    int m_health{100};
};
