#pragma once
#include <exception>

class DeadCharacterException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Персонаж уже мертв";
    }
};

class NoWeaponException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Нет оружия";
    }
};
