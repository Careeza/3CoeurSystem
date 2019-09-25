# include "scene.h"

void    CS_Police::CS_initPolice(std::string police)
{
    CS_font = TTF_OpenFont(police.c_str(), 40);
    if (CS_font == NULL)
    {
        std::cout << "error init police" << std::endl;
        exit (0);
    }
}

void    CS_Police::CS_policeSetting(CS_Color color, int flags, int marginX, int marginY)
{
    CS_flags = flags;
    CS_marginX = marginX;
    CS_marginY = marginY;
    CS_color.r = color.CS_queryRed();
    CS_color.g = color.CS_queryGreen();
    CS_color.b = color.CS_queryBlue();
    CS_color.a = color.CS_queryAlpha();
}

