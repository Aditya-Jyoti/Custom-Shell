#include "Commands.hpp"

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace Commands
{
    void Ls::listContents(fs::path argPath)
    {
        std::cout << std::endl;

        for (fs::directory_entry file : fs::directory_iterator(argPath))
        {
            if (fs::is_directory(file))
            {
                std::cout << file.path().filename().string() << "\\\n";
                continue;
            }
        }

        for (fs::directory_entry file : fs::directory_iterator(argPath))
        {
            if (fs::is_directory(file))
            {
                continue;
            }
            std::cout << file.path().filename().string() << "\n";
        }
    }
}