#include "Keyboard.hpp"

#include <conio.h>
#include <thread>

int Keyboard::getKeyPressed()
{
    int keyPressed;
    while (true)
    {
        if (_kbhit())
        {
            keyPressed = _getch();
            break;
        }
    }

    return keyPressed;
}
