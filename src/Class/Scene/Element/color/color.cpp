#include "scene.h"

CS_Color::CS_Color()
{
    CS_red = 0;
    CS_green = 0;
    CS_blue = 0;
    CS_alpha = 0;
}

CS_Color::CS_Color(int red, int green, int blue, int alpha)
{
    CS_setRed(red);
    CS_setGreen(green);
    CS_setBlue(blue);
    CS_setAlpha(alpha);
}

void    CS_Color::CS_setRed(int red)
{
    CS_red = red;
}

void    CS_Color::CS_setGreen(int green)
{
    CS_green = green;
}

void    CS_Color::CS_setBlue(int blue)
{
    CS_blue = blue;
}

void    CS_Color::CS_setAlpha(int alpha)
{
    CS_alpha = alpha;
}

void    CS_Color::CS_setColor(int red, int green, int blue, int alpha)
{
    CS_setRed(red);
    CS_setGreen(green);
    CS_setBlue(blue);
    CS_setAlpha(alpha);
}

int CS_Color::CS_queryRed()
{
    return (CS_red);
}
        
int CS_Color::CS_queryGreen()
{
    return (CS_green);
}
        
int CS_Color::CS_queryBlue()
{
    return (CS_blue);
}
        
int CS_Color::CS_queryAlpha()
{
    return (CS_alpha);
}
