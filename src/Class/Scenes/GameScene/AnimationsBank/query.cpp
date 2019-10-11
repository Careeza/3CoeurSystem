# include "gameScene.h"

CS_Animation    *CS_BankAnimation::CS_queryAnimationByname(std::string name)
{
    if (noMove->name.compare(name) == 0)
        return (noMove);
    else if (AllenWalker->name.compare(name) == 0)
        return (AllenWalker);
    else
    {
        std::cout << "something went wrong in AnimationBank Query.cpp" << std::endl;
        return (NULL);
    }
}
