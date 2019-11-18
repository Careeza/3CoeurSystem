#include "gameScene.h"

bool        animationOver(int& index, int nbFrame, int interrupt)
{
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

void        hitBoxGestion(SDL_Rect *size)
{
    if (size->x < 0)
        size->x = 0;
    if (size->x > Tools->QueryWindowWidth() - size->w)
        size->x = Tools->QueryWindowWidth() - size->w;
}

bool        CS_Animation::CS_UseAnimation(bool right, SDL_Rect *size, SDL_Rect* &frameDest, SDL_Texture* &textureDest)
{
    std::cout << "l'index int comme un connard " << index << std::endl;
    if (right == true)
    {
        textureDest = textureR;
        size->x += movement[index];
    }
    else
    {
        textureDest = textureL;
        size->x -= movement[index];
    }
    frameDest = frame[index];
    index++;
    std::cout << "nope but only for the first time ?" << std::endl;
    return (animationOver(index, nbFrame, interrupt));
}