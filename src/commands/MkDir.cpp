#include "Commands.hpp"

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace Commands
{
    void MkDir::makeDirectory(fs::path currentPath, std::string dirname)
    {
        fs::path dirpath = currentPath /= dirname;
        if (fs::exists(dirpath))
        {
            throw std::runtime_error("Directory already exists");
        }
        if (fs::create_directory(dirpath))
        {
            std::cout << "\nDirectory " + dirname + " created successfully";
        }
        else
        {
            std::cout << "\nFailed to create directory " + dirname;
        }
    }
}