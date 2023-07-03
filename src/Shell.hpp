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


public:
    Shell();

    void mainLoop();

};

#endif