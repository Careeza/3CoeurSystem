# include "gameScene.h"

void    CS_Character::loadAnimation(std::string name)
{
    animation = bank->CS_queryAnimationByname(name);
    if (animation == NULL)
    {
        std::cout << "we have a prob sir" << std::endl;
        exit (0);
    }
}