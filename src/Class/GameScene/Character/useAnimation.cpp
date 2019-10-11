# include "gameScene.h"

bool    CS_Character::useAnimation(int& i)
{
    if (right == true)
    {
        texture = animation->textureR;
        size->x += animation->movement[i];
        std::cout << "move" << std::endl;
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
