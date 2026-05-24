#pragma once

class BaseCharacter
{
protected:
    double x;
    double y;
    int hp;

public:
    BaseCharacter(double px = 0,
        double py = 0,
        int health = 100);

    void move(double dx,
        double dy);

    bool is_alive() const;

    void get_damage(int amount);

    double get_x() const;
    double get_y() const;

    int get_hp() const;
};
