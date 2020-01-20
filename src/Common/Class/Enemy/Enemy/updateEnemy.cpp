# include "enemy.h"

void                CS_Enemy::setActionToUse(CS_Character *MC)
{
    (void)MC;
}

void                CS_Enemy::updateFrame(int deltaT)
{
    (void)deltaT;
}

void                CS_Enemy::moveCharacter(int deltaT)
{
    (void)deltaT;
}

void                CS_Enemy::getFrame()
{
    texture = animation->QueryTexture(right);
    frame = animation->QueryFrame();
    physic->setHitBox(animation->QueryHitbox(right));
    physic->setAttack(animation->QueryAttack(right));
}
