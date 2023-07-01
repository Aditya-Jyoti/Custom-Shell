#ifndef KEYCODES_HPP
#define KEYCODES_HPP

#include <map>
#include <string>

namespace KeyCodes
{

    std::string GetKeyName(const std::string keycode)
    {
        std::map<std::string, std::string> keymap;
        keymap["8"] = "backspace";
        keymap["9"] = "tab";
        keymap["13"] = "enter";
        keymap["16"] = "shift";
        keymap["17"] = "ctrl";
        keymap["18"] = "alt";
        keymap["19"] = "pause_break";
        keymap["20"] = "caps_lock";
        keymap["27"] = "escape";
        keymap["32"] = " "; // spacebar
        keymap["33"] = "page_up";
        keymap["34"] = "page_down";
        keymap["35"] = "end";
        keymap["36"] = "home";
        keymap["37"] = "left_arrow";
        keymap["38"] = "up_arrow";
        keymap["39"] = "right_arrow";
        keymap["40"] = "down_arrow";
        keymap["45"] = "insert";
        keymap["46"] = "delete";
        keymap["48"] = "0";
        keymap["49"] = "1";
        keymap["50"] = "2";
        keymap["51"] = "3";
        keymap["52"] = "4";
        keymap["53"] = "5";
        keymap["54"] = "6";
        keymap["55"] = "7";
        keymap["56"] = "8";
        keymap["57"] = "9";
        keymap["65"] = "a";
        keymap["66"] = "b";
        keymap["67"] = "c";
        keymap["68"] = "d";
        keymap["69"] = "e";
        keymap["70"] = "f";
        keymap["71"] = "g";
        keymap["72"] = "h";
        keymap["73"] = "i";
        keymap["74"] = "j";
        keymap["75"] = "k";
        keymap["76"] = "l";
        keymap["77"] = "m";
        keymap["78"] = "n";
        keymap["79"] = "o";
        keymap["80"] = "p";
        keymap["81"] = "q";
        keymap["82"] = "r";
        keymap["83"] = "s";
        keymap["84"] = "t";
        keymap["85"] = "u";
        keymap["86"] = "v";
        keymap["87"] = "w";
        keymap["88"] = "x";
        keymap["89"] = "y";
        keymap["90"] = "z";
        keymap["91"] = "left_window_key";
        keymap["92"] = "right_window_key";
        keymap["93"] = "select_key";
        keymap["96"] = "0"; // being numpad
        keymap["97"] = "1";
        keymap["98"] = "2";
        keymap["99"] = "3";
        keymap["100"] = "4";
        keymap["101"] = "5";
        keymap["102"] = "6";
        keymap["103"] = "7";
        keymap["104"] = "8";
        keymap["105"] = "9";
        keymap["106"] = "*";
        keymap["107"] = "+";
        keymap["109"] = "-";
        keymap["110"] = ".";
        keymap["111"] = "/"; // end numpad
        keymap["112"] = "f1";
        keymap["113"] = "f2";
        keymap["114"] = "f3";
        keymap["115"] = "f4";
        keymap["116"] = "f5";
        keymap["117"] = "f6";
        keymap["118"] = "f7";
        keymap["119"] = "f8";
        keymap["120"] = "f9";
        keymap["121"] = "f10";
        keymap["122"] = "f11";
        keymap["123"] = "f12";
        keymap["144"] = "num_lock";
        keymap["145"] = "scroll_lock";
        keymap["186"] = "semi_colon";
        keymap["187"] = "equal_sign";
        keymap["188"] = ",";
        keymap["189"] = "-";
        keymap["190"] = ".";
        keymap["191"] = "/";
        keymap["192"] = "grave_accent";
        keymap["219"] = "open_bracket";
        keymap["220"] = "\\";
        keymap["221"] = "close_braket";
        keymap["222"] = "single_quote";


        return keymap[keycode];
    }
};

#endif