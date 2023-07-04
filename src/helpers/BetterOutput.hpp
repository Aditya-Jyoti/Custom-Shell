#ifndef BETTER_OUTPUT_HPP
#define BETTER_OUTPUT_HPP

#include <string>

namespace BetterOutput
{
    void clearSingleCharacter();
    void clearPartOfOutput(std::string inputString, int clearLength, int startPos);
};

#endif