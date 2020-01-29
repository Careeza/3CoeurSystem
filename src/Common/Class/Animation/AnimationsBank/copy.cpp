# include "gameScene.h"

void            CS_BankAnimation::CopyAnimationBank(CS_BankAnimation *animationBankSource)
{
    int i;
    CS_Animation    *newAnimation;
    CS_Animation    *animationSource; 

    i = 0;
    while (i < animationBankSource->QueryNbAnimation())
    {
        newAnimation = new (CS_Animation);

        animationSource = animationBankSource->QueryAnimation(i);
        newAnimation->CopyAnimation(animationSource);
        animations.push_back(newAnimation);
        i++;
    }
}
