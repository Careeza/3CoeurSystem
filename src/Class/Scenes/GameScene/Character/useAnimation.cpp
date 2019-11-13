# include "gameScene.h"

bool    CS_UseAnimation(bool right, CS_Animation *animation, SDL_Rect *size, SDL_Rect* &frame, SDL_Texture* &texture, int &i)
{
    if (right == true)
    {
        texture = animation->textureR;
        size->x += animation->movement[i];
    }
    else
    {
        texture = animation->textureL;
        size->x -= animation->movement[i];
    }
    if (size->x < 0)
        size->x = 0;
    if (size->x > gameSettings.window_width - size->w)
        size->x = gameSettings.window_width - size->w;
    frame = animation->frame[i];
    i++;
    if (i >= animation->nbFrame)
    {
        i = 0;
        return (true);
    }
    else
        return (false);
}

bool    CS_Character::useAnimation()
{
    return (CS_UseAnimation(right, animation, size, frame, texture, i));
}

void        CS_Character::setRight(bool rightSource)
{
    right = rightSource;
}