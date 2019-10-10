# include "gameScene.h"

CS_Animation    *CS_BankAnimation::CS_queryAnimationByname(std::string name)
{
    if (noMove->name.compare(name) == 0)
        return (noMove);
}
