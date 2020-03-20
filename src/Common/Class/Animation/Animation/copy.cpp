# include "gameScene.h"

void            CS_Animation::CopyAnimation(CS_Animation *animationSource)
{
    name = animationSource->QueryName();
    interrupt = animationSource->QueryAnimationInterrupt();
    textureR = animationSource->QueryTexture(true);
    textureL = animationSource->QueryTexture(false);
//    frame = animationSource->
    hitboxesR = animationSource->QueryHitbox(true);
    hitboxesL = animationSource->QueryHitbox(false);
    attackR = animationSource->QueryAttack(true);
    attackL = animationSource->QueryAttack(false);
    speedX = animationSource->QueryMovementX(true);
    speedY = animationSource->QueryMovementY();
    animationSource->QuerySize(w, h);
    nbFrame = animationSource->QueryMaxIndex();
    nbColumnFrame = animationSource->QueryNbColumnFrame();
    nbLineFrame = animationSource->QueryNbLineFrame();
    std::cout << "nbFrame = " << nbFrame << " nbColumnFrame = " << nbColumnFrame << " nbLineFrame = " << nbLineFrame << std::endl;  
    cutFrame(nbFrame, nbColumnFrame, nbLineFrame);
    animationEnd = false;
    animationTime = animationSource->QueryAnimationTime();
    frameTime = animationTime / (float)nbFrame;
    time = 0;
    index = 0;
    indexStart = 0;
}
