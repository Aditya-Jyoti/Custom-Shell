#include "Keyboard.hpp"

#include <conio.h>
#include <thread>

int Keyboard::getKeyPressed()
{
    int keyPressed = _getch();
    return keyPressed;
}
