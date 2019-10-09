#include "gameScene.h"

CS_Character::CS_Character()
{
    i = 0;
    right = false;
    endAnimation = false;
}

CS_Character::~CS_Character()
{

}

SDL_Texture CS_Character::*queryTexture()
{
    return (texture);
}

SDL_Texture CS_Character::*querySize()
{
    return (size);
}

SDL_Texture CS_Character::*queryFrame()
{
    return (frame);
}