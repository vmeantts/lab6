#include "PasswordError.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        string password = get_password();

        cout << "Пароль принят: "
            << password << endl;
    }
    catch (LengthError& e)
    {
        cout << e.what() << endl;
    }
    catch (RegisterError& e)
    {
        cout << e.what() << endl;
    }
    catch (DigitError& e)
    {
        cout << e.what() << endl;
    }
    catch (ForbiddenLetterError& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}