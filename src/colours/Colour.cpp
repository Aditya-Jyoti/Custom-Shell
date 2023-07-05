#include "Colours.hpp"

#include <iostream>
#include <string>

namespace Colours
{
    int Colour::getR()
    {
        return this->r;
    };
    int Colour::getG()
    {
        return this->g;
    };
    int Colour::getB()
    {
        return this->b;
    };

    void colouredPrint(std::string inputString, Colours::Colour colour)
    {
        std::cout << "\033[38;2;" +
                         std::to_string(colour.getR()) + ";" +
                         std::to_string(colour.getG()) + ";" +
                         std::to_string(colour.getB()) + "m" +
                         inputString + "\033[0m";
    }
}