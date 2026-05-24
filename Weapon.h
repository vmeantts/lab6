#pragma once
#include <iostream>
#include <string>

using namespace std;

class BaseCharacter;

class Weapon
{
private:
    string name;
    int damage;
    double range;

public:
    Weapon();
    Weapon(string n, int d, double r);

    string getName() const;
    int getDamage() const;
    double getRange() const;

    void hit(BaseCharacter& actor,
        BaseCharacter& target);

    friend ostream& operator<<(ostream& out,
        const Weapon& w);

    friend istream& operator>>(istream& in,
        Weapon& w);
};