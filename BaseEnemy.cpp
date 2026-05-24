#include "BaseEnemy.h"

BaseEnemy::BaseEnemy(double x,
    double y,
    Weapon w,
    int hp)
    : BaseCharacter(x, y, hp)
{
    weapon = w;
}

void BaseEnemy::hit(BaseCharacter& target)
{
    weapon.hit(*this, target);
}

ostream& operator<<(ostream& out,
    const BaseEnemy& enemy)
{
    out << "Враг на позиции ("
        << enemy.x
        << ", "
        << enemy.y
        << ") с оружием "
        << enemy.weapon;

    return out;
}