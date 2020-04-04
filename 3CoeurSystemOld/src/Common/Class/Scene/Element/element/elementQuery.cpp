#include "scene.h"

int             CS_Element::QueryElementZIndex()
{
    return(elementZIndex);
}

SDL_Texture     *CS_Element::QueryElementTexture()
{
    if (isElementButton())
    {
        return (elementButton->QueryNoButtonTexture());
    }
    else
    {
        return (elementNoButton->QueryNoButtonTexture());
    }
}

SDL_Rect         *CS_Element::QueryElementSize()
{
    if (isElementButton())
    {
        return (elementButton->QuerySize());
    }
    else
    {
        return (elementNoButton->QuerySize());
    }
}

CS_Border       *CS_Element::QueryBorder()
{
    return (border);
}

CS_Police       *CS_Element::QueryText()
{
    return (text);
}

SDL_Texture     *CS_Element::QueryTextTexture()
{
    return (text->QueryTexte());
}

SDL_Rect        *CS_Element::QueryTextSize()
{
    return (text->QuerySize());
}

CS_Brightness   *CS_Element::QueryBrightness()
{
    return (brightness);
}

std::string     CS_Element::QueryName()
{
    return (name);
}
