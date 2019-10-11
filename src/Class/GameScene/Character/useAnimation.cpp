# include "gameScene.h"

bool    CS_Character::useAnimation(int& i)
{
    if (right == true)
        texture = animation->textureR;
    else
        texture = animation->textureL;
    size = animation->size;
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
