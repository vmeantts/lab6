#pragma once

#include <vector>
#include <string>

#include "BaseCharacter.h"
#include "Weapon.h"

using namespace std;

class BaseEnemy;

class MainHero : public BaseCharacter
{
private:
    string name;

    vector<Weapon> weapons;

    int currentWeapon;

public:
    MainHero(double x,
        double y,
        string n,
        int hp);

    void hit(BaseEnemy& target);

    void add_weapon(Weapon weapon);

    void next_weapon();

    void heal(int amount);
};
