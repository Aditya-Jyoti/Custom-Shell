#include "Shell.hpp"

#include "commands/Commands.hpp"
#include "helpers/Keycodes.hpp"
#include "helpers/CommonFunctions.hpp"
#include "utils/Keyboard.hpp"

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

Shell::Shell()
{
    this->isRunning = true;

    this->currentPath = fs::current_path();

    this->prompt = currentPath.string() + " > ";
    this->input = "";
}

void Shell::updatePrompt()
{
    this->prompt = currentPath.string() + " > ";
}

void Shell::resetPrompt()
{
    std::cout << "\n";
    std::cout << this->prompt;
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
            if (this->input.length() == 0)
            {
                this->resetPrompt();
                continue;
            }

            std::vector<std::string> inputSplit = CommonFunctions::stringSplit(this->input, " ");
            std::string command = inputSplit[0];

            if (command == "cd")
            {
                inputSplit.erase(inputSplit.begin());
                if (inputSplit.size() != 1)
                {
                    throw std::runtime_error("Too many arguments provided, expected 1 got " + std::to_string(inputSplit.size()));
                }

                this->currentPath = Commands::Cd::changeDirectory(this->currentPath, inputSplit[0]);
                this->updatePrompt();
                this->resetPrompt();
            }
            else
            {
                throw std::runtime_error("Command '" + command + "' not recognised as an internal command");
            }
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