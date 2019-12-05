#include "gameScene.h"

void        hitBoxGestion(SDL_Rect *size)
{
    if (size->x < 0)
        size->x = 0;
    if (size->x > Tools->QueryWindowWidth() - size->w)
        size->x = Tools->QueryWindowWidth() - size->w;
}

bool        CS_Animation::nextFrame()
{
    index++;
    if (index >= nbFrame)
    {
        index = 0;
        return (true);
    }
    else
    {
        if (interrupt == INTERRUPT)
            return (true);
        else
            return (false);
    }   
}

bool            CS_Animation::previousFrame()
{
    index--;
    if (index < 0)
    {
        index = nbFrame - 1;
        return (true);
    }
    else
    {
        if (interrupt == INTERRUPT)
            return (true);
        else
            return (false);
    }   
}

void        CS_Animation::getFrame(bool right, SDL_Rect* &frameDest, SDL_Texture* &textureDest)
{
    Tools->verbose(LEVEL3, "sdsd", "animation =", index + 1, "/", nbFrame);
    if (right == true)
        textureDest = textureR;
    else
        textureDest = textureL;
    frameDest = frame[index];
}

void        CS_Animation::moveCharacter(bool right, int& x, int &y)
{
    if (right == true)
        x += movement[index];
    else
        x -= movement[index];
    (void)y;
}