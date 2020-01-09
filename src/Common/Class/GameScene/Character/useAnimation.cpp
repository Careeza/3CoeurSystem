# include "gameScene.h"


void        CS_Character::nextFrame()
{
    animation->nextFrame();
}


void        CS_Character::previousFrame()
{
    animation->previousFrame();
}

void        CS_Character::getFrame()
{
    texture = animation->QueryTexture(right);
    frame = animation->QueryFrame();
}

void        CS_Character::moveCharacter(float deltaT, int BorderMinX, int BorderMaxX)
{
    int w;
    int h;

    physic->updateSpeed(deltaT);
    physic->updatePosition(deltaT);
    QuerySize(w, h);
    verifyHitbox(physic, w, h, BorderMinX, BorderMaxX);
}


void        CS_Character::setRight(bool rightSource)
{
    right = rightSource;
}

void        CS_Character::updateFrame(int deltaT)
{
    animation->nextFrame2(deltaT);
}

void        CS_Character::setAnimationTime(int animationTimeSource)
{
    animation->setAnimationTime(animationTimeSource);
}
