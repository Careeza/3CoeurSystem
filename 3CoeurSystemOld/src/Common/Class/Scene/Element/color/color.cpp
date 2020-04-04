#include "scene.h"

CS_Color::CS_Color()
{
    red = 0;
    green = 0;
    blue = 0;
    alpha = 0;
}

CS_Color::CS_Color(int red, int green, int blue, int alpha)
{
    setRed(red);
    setGreen(green);
    setBlue(blue);
    setAlpha(alpha);
}

void    CS_Color::setRed(int redSource)
{
    red = redSource;
}

void    CS_Color::setGreen(int greenSource)
{
    green = greenSource;
}

void    CS_Color::setBlue(int blueSource)
{
    blue = blueSource;
}

void    CS_Color::setAlpha(int alphaSource)
{
    alpha = alphaSource;
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
