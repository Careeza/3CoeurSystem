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
    else if (action == Dead)
    {
        loadAnimation(DEAD);
        QueryPhysic()->setGravity(0);
        QueryPhysic()->setSpeedY(0);
        if (animation->verifyAnimationEnd())
            physic->increaseHP(-1);
    }
}

void                CS_Enemy::updateFrame(int deltaT)
{
    animation->nextFrame2(deltaT);
}

void                CS_Enemy::moveCharacter(CS_GameScene *scene, int deltaT)
{
    physic->updateSpeed(deltaT);
    physic->updatePosition(scene, deltaT);
}

void                CS_Enemy::getFrame()
{
    texture = animation->QueryTexture(right);
    frame = animation->QueryFrame();
}
