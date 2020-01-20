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

CS_HitBox       *CS_Animation::QueryHitbox(bool right)
{
    if (right)
        return (hitboxesR[index]);
    else
        return (hitboxesL[index]);
}

CS_HitBox       *CS_Animation::QueryAttack(bool right)
{
    if (right)
        return (attackR[index]);
    else
        return (attackL[index]);
}


float           CS_Animation::QueryMovementX(bool right)
{
    if (right)
        return(speedX);
    else
        return(-speedX);
}

float           CS_Animation::QueryMovementY()
{
    return (speedY);
}

void            CS_Animation::QuerySize(int &wDest, int& hDest)
{
    wDest = w;
    hDest = h;
}

int             CS_Animation::QueryAnimationTime()
{
    return (animationTime);
}

int             CS_Animation::QueryIndex()
{
    return (index);
}

int             CS_Animation::QueryMaxIndex()
{
    return (nbFrame);
}