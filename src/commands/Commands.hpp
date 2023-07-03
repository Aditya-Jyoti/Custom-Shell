#ifndef COMMANDS_H
#define COMMANDS_H

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace Commands
{
    class Cd
    {
    public:
        static fs::path changeDirectory(fs::path currentPath, std::string arg);
    };
};

#endif