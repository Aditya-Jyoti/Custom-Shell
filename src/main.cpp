#include <iostream>
#include <thread>
#include <chrono>

#include "helpers/Keyboard.hpp"
#include "utils/constants.hpp"
#include "utils/keycodes.hpp"

int main(int argc, char *argv[])
{
    Keyboard keyboard;

    std::string typed = "";

    int key = keyboard.getKeyPressed();
    while (key != constants::ENTER_KEY)
    {
        if (key != -1)
        {
            typed += KeyCodes::GetKeyName(std::to_string(key));
            std::cout << typed << "\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        key = keyboard.getKeyPressed();
    }

    return 0;
}
