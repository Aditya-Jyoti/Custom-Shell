#ifndef SHELL_HPP
#define SHELL_HPP

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class Shell
{
private:
    bool isRunning;

    fs::path currentPath;

    std::string prompt;
    std::string input;

    int cursorPosition;

    void setPrompt();
    void updatePrompt();
    void resetPrompt();

public:
    Shell();

    void mainLoop();
};

#endif