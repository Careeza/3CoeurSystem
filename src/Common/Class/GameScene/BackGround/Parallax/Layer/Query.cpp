#include "gameScene.h"

SDL_Texture         *CS_Layer::queryTexture()
{
    return (layerTexture);
}

SDL_Rect            *CS_Layer::queryScopeMain()
{
    return (scopeMain);
}

SDL_Rect            *CS_Layer::querySizeMain()
{
    return (sizeMain);
}

SDL_Rect            *CS_Layer::queryScopeSecond()
{
    return (scopeSecond);
}

SDL_Rect            *CS_Layer::querySizeSecond()
{
    return (sizeSecond);
}

int         CS_Layer::queryZindex()
{
    return (zIndex);
}

bool        CS_Layer::secondScopeNeeded()
{
    return (needSecondScope);
}
