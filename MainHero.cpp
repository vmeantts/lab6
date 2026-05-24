#include "MainHero.h"
#include "BaseEnemy.h"
#include "GameExceptions.h"

MainHero::MainHero(double x,
    double y,
    string n,
    int hp)
    : BaseCharacter(x, y, hp)
{
    name = n;
    currentWeapon = 0;
}

void MainHero::add_weapon(Weapon weapon)
{
    weapons.push_back(weapon);

    cout << "Подобрал "
        << weapon
        << endl;
}

void MainHero::next_weapon()
{
    if (weapons.empty())
    {
        throw NoWeaponException();
    }

    if (weapons.size() == 1)
    {
        cout << "У меня только одно оружие\n";
        return;
    }

    currentWeapon++;

    if (currentWeapon >= weapons.size())
        currentWeapon = 0;

    cout << "Сменил оружие на "
        << weapons[currentWeapon]
        << endl;
}

void MainHero::hit(BaseEnemy& target)
{
    if (weapons.empty())
    {
        throw NoWeaponException();
    }

    weapons[currentWeapon].hit(*this, target);
}

void MainHero::heal(int amount)
{
    hp += amount;

    if (hp > 200)
        hp = 200;

    cout << "Полечился, теперь здоровья "
        << hp
        << endl;
}