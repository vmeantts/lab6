#pragma once
#include <iostream>
#include <string>

using namespace std;

class PasswordError : public exception
{
protected:
    string message;

public:
    PasswordError(string msg);
    const char* what() const noexcept override;
};

class LengthError : public PasswordError
{
public:
    LengthError();
};

class RegisterError : public PasswordError
{
public:
    RegisterError();
};

class DigitError : public PasswordError
{
public:
    DigitError();
};

class ForbiddenLetterError : public PasswordError
{
public:
    ForbiddenLetterError();
};

string get_password();
