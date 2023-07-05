#include "CleanOutput.hpp"

#include <iostream>
#include <string>

// TODO: write function to delete entire words and maintain buffer
namespace CleanOutput
{
    void clearSingleCharacter()
    {
        std::cout << "\b";
        std::cout << " ";
        std::cout << "\b";
    }
}