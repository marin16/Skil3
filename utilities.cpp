#include "utilities.h"

#include <sstream>

namespace utils {
    std::string stringToLower(std::string str)
    {
        std::string result = "";

        for (unsigned int i = 0; i < str.length(); i++)
        {
            char currentCharacter = str[i];

            // http://www.asciitable.com/
            if (currentCharacter <= 90 && currentCharacter >= 65)
            {
                result += currentCharacter + 32;
            }
            else
            {
                result += currentCharacter;
            }
        }

        return result;
    }
    std::string intToString(int number)
    {
        std::stringstream stream;
        stream << number;
        return stream.str();
    }
}
