#ifndef KEYCODES_HPP
#define KEYCODES_HPP

#include <map>
#include <string>

namespace Keycodes
{
    constexpr int ENTER_KEY = 13;
    std::string getKeyName(const std::string keycode);
};

#endif