#include "Keyboard.hpp"
#include "utils/constants.hpp"

#include <Windows.h>
#include <thread>

Keyboard::Keyboard()
{
    this->isRunning = true;
    this->keyPressed = -1;

    this->thread = std::thread(&Keyboard::readKeyPress, this);
}

Keyboard::~Keyboard()
{
    this->isRunning = false;

    if (this->thread.joinable())
    {
        thread.join();
    }
}

void Keyboard::readKeyPress()
{
    while (this->isRunning)
    {
        this->keyPressed = -1;
        for (int key = 1; key < 255; key++)
        {
            if (GetAsyncKeyState(key) & 0x8000)
            {
                if (key == constants::ENTER_KEY)
                {
                    this->isRunning = false;

                    if (this->thread.joinable())
                    {
                        thread.join();
                    }
                    return;
                }

                this->keyPressed = key;
            }
        }
    }
}

int Keyboard::getKeyPressed()
{
    return this->keyPressed;
}