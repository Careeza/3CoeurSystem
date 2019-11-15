# include "gameScene.h"

CS_Animation    *CS_BankAnimation::CS_queryAnimationByname(t_animation nameSource)
{
    int i;

    i = 0;
    while (i < animations.size())
    {
        if (animations[i]->QueryName() == nameSource)
            return (animations[i]);
    }
    std::cout << "error in query animation" << std::endl;
    exit (0);
}
