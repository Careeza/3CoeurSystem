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
    setRed(red);
    setGreen(green);
    setBlue(blue);
    setAlpha(alpha);
}

void    CS_Color::setRed(int red)
{
    red = red;
}

void    CS_Color::setGreen(int green)
{
    green = green;
}

void    CS_Color::setBlue(int blue)
{
    blue = blue;
}

void    CS_Color::setAlpha(int alpha)
{
    alpha = alpha;
}

void    CS_Color::setColor(int red, int green, int blue, int alpha)
{
    setRed(red);
    setGreen(green);
    setBlue(blue);
    setAlpha(alpha);
}

int CS_Color::QueryRed()
{
    return (red);
}
        
int CS_Color::QueryGreen()
{
    return (green);
}
        
int CS_Color::QueryBlue()
{
    return (blue);
}
        
int CS_Color::QueryAlpha()
{
    return (alpha);
}
