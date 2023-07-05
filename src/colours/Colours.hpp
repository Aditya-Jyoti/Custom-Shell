#ifndef COLOURS_HPP
#define COLOURS_HPP

#include <string>

namespace Colours
{
    struct Colour
    {
    private:
        int r;
        int g;
        int b;

    public:
        Colour(int r, int g, int b) : r(r), g(g), b(b) {}

        int getR();
        int getG();
        int getB();
    };

    struct Theme
    {
        Colour background;

        Colour text;
        Colour subtext;

        Colour accent;

        Colour blue;
        Colour green;
        Colour yellow;
        Colour orange;
        Colour red;
        Colour pink;

        Theme(Colour background, Colour text, Colour subtext, Colour accent, Colour blue, Colour green, Colour yellow, Colour orange, Colour red, Colour pink)
            : background(background), text(text), subtext(subtext), accent(accent), blue(blue), green(green), yellow(yellow), orange(orange), red(red), pink(pink) {}
    };

    extern Theme catppuccin;
    extern Theme nord;

    void colouredPrint(std::string inputString, Colours::Colour colour);
};

#endif