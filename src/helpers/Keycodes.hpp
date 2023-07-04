#ifndef KEYCODES_HPP
#define KEYCODES_HPP

#include <string>

// TODO: Check for arrow key presses
// currently conflict with uppercase K and M keys
namespace Keycodes
{
    constexpr int ENTER_KEY = 13;
    constexpr int ESCAPE_KEY = 27;
    constexpr int BACKSPACE_KEY = 8;

    // constexpr int LEFT_ARROW = 75;
    // constexpr int RIGHT_ARROW = 77;

    std::string getKeyName(const std::string keycode);
};

#endif