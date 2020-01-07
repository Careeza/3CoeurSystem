# include "gameScene.h"

t_animation     CS_Animation::QueryName()
{
    return (name);
}

SDL_Texture     *CS_Animation::QueryTexture(bool right)
{
    if (right)
        return (textureR);
    else
        return (textureL);
}

SDL_Rect        *CS_Animation::QueryFrame()
{
    return(frame[index]);
}

int     CS_Animation::QueryMovementX(bool right)
{
    if (right)
        return(speedX);
    else
        return(-speedX);
}

int     CS_Animation::QueryMovementY()
{
    return (speedY);
}

void            CS_Animation::QuerySize(int &wDest, int& hDest)
{
    wDest = w;
    hDest = h;
}
