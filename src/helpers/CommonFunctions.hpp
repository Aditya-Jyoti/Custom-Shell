#ifndef COMMON_FUNCTIONS_HPP
#define COMMON_FUNCTIONS_HPP

#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

namespace CommonFunctions
{
    std::vector<std::string> stringSplit(std::string inputString, std::string separator);
    int getPathDepth(fs::path &currentPath);
}

#endif