#include "Shell.hpp"

#include "colours/Colours.hpp"

#include "commands/Commands.hpp"

#include "helpers/Keycodes.hpp"
#include "helpers/CommonFunctions.hpp"

#include "utils/CleanOutput.hpp"
#include "utils/Keyboard.hpp"

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

// TODO: accept nerdfont glyphs

namespace fs = std::filesystem;

Shell::Shell()
{
    this->isRunning = true;

    this->currentPath = fs::current_path();

    this->setPrompt();
    this->input = "";

    this->cursorPosition = 0;
}

void Shell::setPrompt()
{
    // TODO: Truncate path length
    this->prompt = this->currentPath.string() + " > ";
}

void Shell::updatePrompt()
{
    this->prompt = currentPath.string() + " > ";
}

void Shell::resetPrompt()
{
    std::cout << "\n";
    Colours::colouredPrint(this->prompt, Colours::catppuccin.accent);

    this->input = "";
    this->cursorPosition = 0;
}

void Shell::mainLoop()
{
    Colours::colouredPrint(this->prompt, Colours::catppuccin.accent);
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
                this->setPrompt();
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
                this->setPrompt();
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

            CleanOutput::clearSingleCharacter();
            this->cursorPosition -= 1;
            this->input.pop_back();
        }
        else
        {
            this->cursorPosition += 1;
            this->input += Keycodes::getKeyName(std::to_string(keyPressed));
            std::cout << Keycodes::getKeyName(std::to_string(keyPressed));
        }
    }
}