# include "gameScene.h"

bool    CS_Character::useAnimation()
{
    std::cout << "crash here ?" << std::endl;
    return (animation->CS_UseAnimation(right, size, frame, texture));
}

void        CS_Character::setRight(bool rightSource)
{
    right = rightSource;
}