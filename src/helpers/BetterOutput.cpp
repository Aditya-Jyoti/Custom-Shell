#include "BetterOutput.hpp"

#include <iostream>
#include <string>

// TODO: Write better and cleaner code
namespace BetterOutput
{
    void clearSingleCharacter()
    {
        std::cout << "\b";
        std::cout << " ";
        std::cout << "\b";
    }

    void clearPartOfOutput(std::string inputString, int clearLength, int startPos)
    {
        for (int i = 0; i < inputString.length() - startPos; i++)
        {
            std::cout << "\b";
        }
        for (int i = 0; i < clearLength; i++)
        {
            std::cout << "\b";
            std::cout << " ";
            std::cout << "\b";
        }
    }
}