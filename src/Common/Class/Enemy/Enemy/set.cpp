# include "enemy.h"

void        CS_Enemy::setID(int idSource)
{
    id = idSource;
}

void        CS_Enemy::loadAnimation(t_animation name)
{
    CS_Animation    *newAnimation;

    newAnimation = animationBank->QueryAnimationByname(name);
    if (newAnimation == NULL)
    {
        std::cout << "error in loadAnimation => MC" << std::endl;
        exit (0);
    }
    if (newAnimation != animation)
    {
        animation = newAnimation;
        animation->restartAnimation();
    }
    physic->setSpeedX(animation->QueryMovementX(right));
    physic->setHitBox(animation->QueryHitbox(right));
    physic->setAttack(animation->QueryAttack(right));
}

void        CS_Enemy::setName(t_enemy nameSource)
{
    name = nameSource;
}

void        CS_Enemy::setHP(int hpSource)
{
    physic->setHP(hpSource);
}

void        CS_Enemy::increaseHP(int hpSource)
{
    physic->increaseHP(hpSource);
}
