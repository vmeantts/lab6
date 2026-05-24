#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(double px,
    double py,
    int health)
{
    x = px;
    y = py;
    hp = health;
}

void BaseCharacter::move(double dx,
    double dy)
{
    x += dx;
    y += dy;
}

bool BaseCharacter::is_alive() const
{
    return hp > 0;
}

void BaseCharacter::get_damage(int amount)
{
    hp -= amount;

    if (hp < 0)
        hp = 0;
}

double BaseCharacter::get_x() const
{
    return x;
}

double BaseCharacter::get_y() const
{
    return y;
}

int BaseCharacter::get_hp() const
{
    return hp;
}