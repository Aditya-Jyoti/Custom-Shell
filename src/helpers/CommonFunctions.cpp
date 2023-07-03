#include "CommonFunctions.hpp"

#include <string>
#include <vector>

namespace CommonFunctions
{
    std::vector<std::string> stringSplit(std::string inputString, std::string separator)
    {
        std::vector<std::string> splitStringVector;
        int startPos = 0;
        int endPos = inputString.find(separator);

        while (endPos != std::string::npos)
        {
            std::string split = inputString.substr(startPos, endPos - startPos);
            splitStringVector.push_back(split);

            startPos = endPos + separator.length();
            endPos = inputString.find(separator, startPos);
        }

        splitStringVector.push_back(inputString.substr(startPos));

        return splitStringVector;
    }
}