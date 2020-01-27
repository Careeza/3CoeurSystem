# include "enemy.h"
# include "gameScene.h"

void                CS_Enemy::setActionToUse(CS_Character *MC)
{
    t_enemyAction action;
    
    action = algo(MC, physic);
    if (action == WalkR)
    {
        right = true;
        loadAnimation(WALK); 
    }
    else if (action == WalkL)
    {
        right = false;
        loadAnimation(WALK);
    }
    else if (action == AttR)
    {
        right = true;
        loadAnimation(ATTACK);
    }
    else if (action == AttL)
    {
        right = false;
        loadAnimation(ATTACK);
    }
}

void                CS_Enemy::updateFrame(int deltaT)
{
    animation->nextFrame2(deltaT);
}

void                CS_Enemy::moveCharacter(int deltaT)
{
    physic->updateSpeed(deltaT);
//    physic->updatePosition(deltaT);
}

void                CS_Enemy::getFrame()
{
    texture = animation->QueryTexture(right);
    frame = animation->QueryFrame();
    physic->setHitBox(animation->QueryHitbox(right));
    physic->setAttack(animation->QueryAttack(right));
}
