#include "gameScene.h"

SDL_Texture         *CS_Layer::QueryTexture()
{
    return (layerTexture);
}

SDL_Rect            *CS_Layer::QueryScopeMain()
{
    return (scopeMain);
}

SDL_Rect            *CS_Layer::QuerySizeMain()
{
    return (sizeMain);
}

SDL_Rect            *CS_Layer::QueryScopeSecond()
{
    return (scopeSecond);
}

SDL_Rect            *CS_Layer::QuerySizeSecond()
{
    return (sizeSecond);
}

int         CS_Layer::QueryZindex()
{
    return (zIndex);
}

bool        CS_Layer::secondScopeNeeded()
{
    return (needSecondScope);
}
