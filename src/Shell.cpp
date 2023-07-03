#include "Shell.hpp"

#include "helpers/Keycodes.hpp"
#include "utils/Keyboard.hpp"

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

Shell::Shell()
{
    this->isRunning = true;

    this->currentPath = fs::current_path();

    this->prompt = currentPath.string() + " > ";
    this->input = "";
}

void Shell::mainLoop()
{
    std::cout << this->prompt;
    while (this->isRunning)
    {
        int keyPressed = Keyboard::getKeyPressed();

        if (keyPressed == Keycodes::ESCAPE_KEY)
        {
            this->isRunning = false;
        }
        else if (keyPressed == Keycodes::ENTER_KEY)
        {
            std::cout << "\n";
            std::cout << this->prompt;
            this->input = "";

            // TODO: handle function running
        }
        else if (keyPressed == Keycodes::BACKSPACE_KEY)
        {
            if (this->input.length() == 0)
            {
                continue;
            }

            std::cout << "\b";
            std::cout << " ";
            std::cout << "\b";
            this->input.pop_back();
        }
        else
        {
            this->input += Keycodes::getKeyName(std::to_string(keyPressed));
            std::cout << Keycodes::getKeyName(std::to_string(keyPressed));
        }
    }
}