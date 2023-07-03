#include "Keycodes.hpp"

#include <map>
#include <string>

namespace Keycodes
{
    std::string getKeyName(const std::string keycode)
    {
        std::map<std::string, std::string> keymap;
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

        keymap["65"] = "A";
        keymap["66"] = "B";
        keymap["67"] = "C";
        keymap["68"] = "D";
        keymap["69"] = "E";
        keymap["70"] = "F";
        keymap["71"] = "G";
        keymap["72"] = "H";
        keymap["73"] = "I";
        keymap["74"] = "J";
        keymap["75"] = "K";
        keymap["76"] = "L";
        keymap["77"] = "M";
        keymap["78"] = "N";
        keymap["79"] = "O";
        keymap["80"] = "P";
        keymap["81"] = "Q";
        keymap["82"] = "R";
        keymap["83"] = "S";
        keymap["84"] = "T";
        keymap["85"] = "U";
        keymap["86"] = "V";
        keymap["87"] = "W";
        keymap["88"] = "X";
        keymap["89"] = "Y";
        keymap["90"] = "Z";

        keymap["97"] = "a";
        keymap["98"] = "b";
        keymap["99"] = "c";
        keymap["100"] = "d";
        keymap["101"] = "e";
        keymap["102"] = "f";
        keymap["103"] = "g";
        keymap["104"] = "h";
        keymap["105"] = "i";
        keymap["106"] = "j";
        keymap["107"] = "k";
        keymap["108"] = "l";
        keymap["109"] = "m";
        keymap["110"] = "n";
        keymap["111"] = "o";
        keymap["112"] = "p";
        keymap["113"] = "q";
        keymap["114"] = "r";
        keymap["115"] = "s";
        keymap["116"] = "t";
        keymap["117"] = "u";
        keymap["118"] = "v";
        keymap["119"] = "w";
        keymap["120"] = "x";
        keymap["121"] = "y";
        keymap["122"] = "z";

        keymap["32"] = " ";

        keymap["27"] = "esc";
        keymap["8"] = "backspace";

        return keymap[keycode];
    }
}