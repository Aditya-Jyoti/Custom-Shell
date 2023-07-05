#include "Commands.hpp"

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace Commands
{
    void RmDir::removeDirectory(fs::path currentPath, std::string dirname)
    {
        fs::path dirpath = currentPath /= dirname;
        if (!fs::exists(dirpath))
        {
            throw std::runtime_error("Directory does not exist");
        }
        if (fs::remove_all(dirpath))
        {
            std::cout << "\nDirectory " + dirname + " removed successfully";
        }
        else
        {
            std::cout << "\nFailed to remove directory " + dirname;
        }
    }
}