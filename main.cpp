#include <iostream>

#include "Weapon.h"
#include "BaseEnemy.h"
#include "MainHero.h"
#include "GameExceptions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Weapon sword("Меч", 30, 3);
    Weapon axe("Топор", 50, 2);

    MainHero hero(0, 0,
        "Артур",
        150);

    hero.add_weapon(sword);
    hero.add_weapon(axe);

    BaseEnemy enemy1(2, 0,
        sword,
        100);

    BaseEnemy enemy2(10, 0,
        axe,
        100);

    int choice;

    do
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Показать врагов\n";
        cout << "2 - Атаковать врага 1\n";
        cout << "3 - Атаковать врага 2\n";
        cout << "4 - Сменить оружие\n";
        cout << "5 - Полечиться\n";
        cout << "6 - Переместиться\n";
        cout << "7 - Враг 1 атакует героя\n";
        cout << "8 - Ввести новое оружие\n";
        cout << "0 - Выход\n";

        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cout << enemy1 << endl;
                cout << enemy2 << endl;
                break;

            case 2:
                hero.hit(enemy1);
                break;

            case 3:
                hero.hit(enemy2);
                break;

            case 4:
                hero.next_weapon();
                break;

            case 5:
            {
                int heal;

                cout << "Сколько здоровья добавить: ";
                cin >> heal;

                hero.heal(heal);
                break;
            }

            case 6:
            {
                double dx, dy;

                cout << "Введите dx и dy: ";

                cin >> dx >> dy;

                hero.move(dx, dy);

                cout << "Новая позиция: ("
                    << hero.get_x()
                    << ", "
                    << hero.get_y()
                    << ")\n";

                break;
            }

            case 7:
                enemy1.hit(hero);
                break;

            case 8:
            {
                Weapon newWeapon;

                cin >> newWeapon;

                hero.add_weapon(newWeapon);

                break;
            }

            case 0:
                cout << "Выход\n";
                break;

            default:
                cout << "Неверный пункт меню\n";
            }
        }
        catch (NoWeaponException& e)
        {
            cout << e.what() << endl;
        }
        catch (DeadCharacterException& e)
        {
            cout << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}