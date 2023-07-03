#include "Commands.hpp"

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace Commands
{
    fs::path Cd::changeDirectory(fs::path currentPath, std::string arg)
    {
        if (arg == "..")
        {
            return currentPath.parent_path();
        }
        else
        {
            for (fs::directory_entry file : fs::directory_iterator(currentPath))
            {
                if (fs::is_directory(file.path()) && arg == file.path().filename().string())
                {
                    return currentPath /= file.path();
                }
            }
            throw std::runtime_error("Directory not found");
        }
    }
};