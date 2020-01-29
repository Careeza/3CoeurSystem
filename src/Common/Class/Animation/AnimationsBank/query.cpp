# include "gameScene.h"

CS_Animation    *CS_BankAnimation::QueryAnimationByname(t_animation nameSource)
{
    unsigned long i;

    i = 0;
//    std::cout << "currentlt have " << animations.size() << " animation(s)" << std::endl;
    while (i < animations.size())
    {
        if (animations[i]->QueryName() == nameSource)
            return (animations[i]);
        i++;
    }
    std::cout << "error in Query(enculé fred) animation = " << nameSource << " looking for > " << STATIC << "or > " << WALK << std::endl;
    exit (0);
}

int             CS_BankAnimation::QueryNbAnimation()
{
    return (animations.size());
}

CS_Animation    *CS_BankAnimation::QueryAnimation(int index)
{
    return (animations[index]);
}
