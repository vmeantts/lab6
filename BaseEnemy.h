#pragma once
#include "BaseCharacter.h"
#include "Weapon.h"

class BaseEnemy : public BaseCharacter
{
private:
    Weapon weapon;

public:
    BaseEnemy(double x,
        double y,
        Weapon w,
        int hp);

    void hit(BaseCharacter& target);

    friend ostream& operator<<(ostream& out,
        const BaseEnemy& enemy);
};
