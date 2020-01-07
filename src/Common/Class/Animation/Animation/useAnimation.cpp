#include "gameScene.h"

void        CS_Animation::getFrame(bool right, SDL_Rect* &frameDest, SDL_Texture* &textureDest)
{
    Tools->verbose(LEVEL3, "sdsd", "animation =", index + 1, "/", nbFrame);
    if (right == true)
        textureDest = textureR;
    else
        textureDest = textureL;
    frameDest = frame[index];
}