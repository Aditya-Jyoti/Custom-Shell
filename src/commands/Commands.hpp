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

    class Ls
    {
    public:
        static void listContents(fs::path argPath);
    };
    class MkDir
    {
    public:
        static void makeDirectory(fs::path currentPath, std::string dirname);
    };
    class RmDir
    {
    public:
        static void removeDirectory(fs::path currentPath, std::string dirname);
    };
};

#endif