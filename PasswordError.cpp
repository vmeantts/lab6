#include "PasswordError.h"

PasswordError::PasswordError(string msg)
{
    message = msg;
}

const char* PasswordError::what() const noexcept
{
    return message.c_str();
}

LengthError::LengthError()
    : PasswordError("Ошибка: пароль короче 9 символов")
{
}

RegisterError::RegisterError()
    : PasswordError("Ошибка: все буквы одного регистра")
{
}

DigitError::DigitError()
    : PasswordError("Ошибка: нет цифр")
{
}

ForbiddenLetterError::ForbiddenLetterError()
    : PasswordError("Ошибка: запрещенные символы (l, I, 1, o, O, 0)")
{
}

string get_password()
{
    string password;

    cout << "Введите пароль: ";
    cin >> password;

    if (password.length() < 9)
        throw LengthError();

    bool hasUpper = false;
    bool hasLower = false;

    for (char c : password)
    {
        if (isupper(c))
            hasUpper = true;

        if (islower(c))
            hasLower = true;
    }

    if (!(hasUpper && hasLower))
        throw RegisterError();

    bool hasDigit = false;

    for (char c : password)
    {
        if (isdigit(c))
            hasDigit = true;
    }

    if (!hasDigit)
        throw DigitError();

    for (char c : password)
    {
        if (c == 'l' || c == 'I' || c == '1' ||
            c == 'o' || c == 'O' || c == '0')
        {
            throw ForbiddenLetterError();
        }
    }

    return password;
}