#include "Shell.hpp"

#include "commands/Commands.hpp"

#include "helpers/BetterOutput.hpp"
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

    this->cursorPosition = 0;
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
    this->cursorPosition = 0;
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
            else if (command == "ls")
            {
                // TODO: accept path arguments

                inputSplit.erase(inputSplit.begin());
                if (inputSplit.size() != 0)
                {
                    throw std::runtime_error("Too many arguments provided, expected 0 got " + std::to_string(inputSplit.size()));
                }

                Commands::Ls::listContents(this->currentPath);
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

            BetterOutput::clearSingleCharacter();
            this->input.pop_back();
        }
        // else if (keyPressed == Keycodes::LEFT_ARROW)
        // {
        //     if (this->cursorPosition == 0)
        //     {
        //         continue;
        //     }
        //     std::cout << "\x1b[1D";
        //     this->cursorPosition -= 1;
        // }
        // else if (keyPressed == Keycodes::RIGHT_ARROW)
        // {
        //     if (this->cursorPosition == this->input.length())
        //     {
        //         continue;
        //     }
        //     std::cout << "\x1b[5C";
        //     this->cursorPosition += 1;
        // }
        else
        {
            this->cursorPosition += 1;
            this->input += Keycodes::getKeyName(std::to_string(keyPressed));
            std::cout << Keycodes::getKeyName(std::to_string(keyPressed));
        }
    }
}