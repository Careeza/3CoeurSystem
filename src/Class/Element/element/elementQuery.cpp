#include "scene.h"

int             CS_Element::CS_queryElementZIndex()
{
    return(elementZIndex);
}

SDL_Texture     *CS_Element::CS_queryElementTexture()
{
    if (CS_isElementButton())
    {
        return (elementButton->CS_queryNoButtonTexture());
    }
    else
    {
        return (elementNoButton->CS_queryNoButtonTexture());
    }
}

SDL_Rect         *CS_Element::CS_queryElementSize()
{
    if (CS_isElementButton())
    {
        return (elementButton->CS_QuerySize());
    }
    else
    {
        return (elementNoButton->CS_QuerySize());
    }
}

CS_Border       *CS_Element::CS_queryBorder()
{
    return (border);
}

CS_Police       *CS_Element::CS_queryText()
{
    return (text);
}

SDL_Texture     *CS_Element::CS_queryTextTexture()
{
    return (text->CS_queryTexte());
}

SDL_Rect        *CS_Element::CS_queryTextSize()
{
    return (text->querySize());
}

CS_Brightness   *CS_Element::CS_queryBrightness()
{
    return (brightness);
}
