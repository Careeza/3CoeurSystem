# include "gameScene.h"

bool    CS_Character::useAnimation(int& i)
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
    frame = &animation->frame[i];
    i++;
    if (i == animation->nbFrame)
    {
        i = 0;
        return (true);
    }
    else
        return (false);
}

void        CS_Character::setRight(bool rightSource)
{
    right = rightSource;
}
