#include "scene.h"

void            CS_Element::setPoliceSettings(CS_Color color, int flags, int marginX, int marginY)
{
    text = new (CS_Police);
    haveText = true;
    text->CS_policeSetting(color, flags, marginX, marginY);
}

void            CS_Element::CS_addTextToElement(std::string comment, SDL_Renderer *render)
{
    text->CS_writeTexte(comment, CS_queryElementSize(), render);
}

SDL_Texture     *CS_Element::CS_queryTextTexture()
{
    return(text->CS_queryTexte());
}

SDL_Rect        *CS_Element::CS_queryTextSize()
{
    return(text->querySize());
}

bool            CS_Element::CS_haveText()
{
    return(haveText);
}
