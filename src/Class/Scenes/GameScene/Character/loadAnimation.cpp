# include "gameScene.h"

void        CS_Character::loadAnimation(std::string name)
{
    static CS_Animation *save = NULL;

    animation = bank->CS_queryAnimationByname(name);
    if (save != animation)
    {
        save = animation;
        i = 0;
    }
    if (animation == NULL)
    {
        std::cout << "we have a prob sir" << std::endl;
        exit (0);
    }
}