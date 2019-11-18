# include "gameScene.h"

CS_Animation    *CS_BankAnimation::CS_queryAnimationByname(t_animation nameSource)
{
    unsigned long i;

    i = 0;
    std::cout << "currentlt have " << animations.size() << " animation(s)" << std::endl;
    while (i < animations.size())
    {
        if (animations[i]->QueryName() == nameSource)
            return (animations[i]);
    }
    std::cout << "error in query animation = " << nameSource << " looking for > " << STATIC << "or > " << WALK << std::endl;
    exit (0);
}
