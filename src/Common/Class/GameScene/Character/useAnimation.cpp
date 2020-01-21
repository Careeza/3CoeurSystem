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

void        CS_Character::moveCharacter(int deltaT, int BorderMinX, int BorderMaxX)
{
    int w;
    int h;

    physic->updateSpeed(deltaT);
    physic->updatePosition(deltaT);
    physic->setHitBox(animation->QueryHitbox(right));
    physic->setAttack(animation->QueryAttack(right));
    animation->QuerySize(w, h);
    verifyHitbox2(w, h, physic, NULL);
    setOnGround(physic->verifyOnGround());
    if (onGround)
        jump = maxJump;
}

void        CS_Character::useJump()
{
    if (jump > 0)
    {
        QueryPhysic()->setSpeedY(-1);
        jump--;
    }
}



void        CS_Character::setRight(bool rightSource)
{
    right = rightSource;
}

void        CS_Character::setOnGround(bool onGroundSource)
{
    onGround = onGroundSource;
}

void        CS_Character::setMaxJump(int maxJumpSource)
{
    maxJump = maxJumpSource;
}


void        CS_Character::updateFrame(int deltaT)
{
    animation->nextFrame2(deltaT);
}

void        CS_Character::setAnimationTime(int animationTimeSource)
{
    animation->setAnimationTime(animationTimeSource);
}