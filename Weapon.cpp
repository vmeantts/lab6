#include "Weapon.h"
#include "BaseCharacter.h"
#include "GameExceptions.h"

#include <cmath>

Weapon::Weapon()
{
    name = "Без имени";
    damage = 0;
    range = 0;
}

Weapon::Weapon(string n, int d, double r)
{
    name = n;
    damage = d;
    range = r;
}

string Weapon::getName() const
{
    return name;
}

int Weapon::getDamage() const
{
    return damage;
}

double Weapon::getRange() const
{
    return range;
}

void Weapon::hit(BaseCharacter& actor,
    BaseCharacter& target)
{
    if (!target.is_alive())
    {
        throw DeadCharacterException();
    }

    double dx = actor.get_x() - target.get_x();
    double dy = actor.get_y() - target.get_y();

    double distance = sqrt(dx * dx + dy * dy);

    if (distance > range)
    {
        cout << "Враг слишком далеко для оружия "
            << name << endl;

        return;
    }

    cout << "Врагу нанесен урон оружием "
        << name
        << " в размере "
        << damage
        << endl;

    target.get_damage(damage);
}

ostream& operator<<(ostream& out,
    const Weapon& w)
{
    out << w.name;

    return out;
}

istream& operator>>(istream& in,
    Weapon& w)
{
    cout << "Название оружия: ";
    in >> w.name;

    cout << "Урон: ";
    in >> w.damage;

    cout << "Радиус атаки: ";
    in >> w.range;

    return in;
}




