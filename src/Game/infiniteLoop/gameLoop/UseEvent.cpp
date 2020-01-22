#include "game.h"

t_pos   gameUseEvent(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_Timer *timer)
{
    if (action.escape == KeyPress)
    {
        timer->pause();
        render->saveScreen();
        if (loopMenu(render, value, actionTable))
        {
            timer->unpause();
            return (home);
        }
        else
        {
            timer->unpause();
            return (game);
        }
    }
    return (game);
}


void    walkMC(CS_Character *MC)
{
    if (MC->verifyOnGround())
    {
        MC->loadAnimation(WALK);
    }
    else
    {
        if (MC->QueryPhysic()->QuerySpeedY() < 0)
        {
            MC->loadAnimation(JUMP); //HOTFIX
        }
        else
        {
            MC->loadAnimation(JUMP); //HOTFIX
        }
    }
}

void    useAttack(CS_GameScene *scene)
{
    CS_Character    *MC;
    int             x;
    int             y;
    int             w;
    int             h;

    MC = scene->QueryMC();
    if (MC->MCIsMoine())
        MC->loadAnimation(ATTACK);
    else
    {
        MC->loadAnimation(ATTACK);
        MC->QueryPhysic()->QueryHitBox(w, h, x, y);
        if (MC->VerifyRight())
            scene->QueryProjectile()->spawnProjectile(projectile3, x + w, y + h / 4, true);
        else
            scene->QueryProjectile()->spawnProjectile(projectile3, x, y + h / 4, false);
    }    
}

void    useAction(t_action *table, CS_GameScene *scene)
{
    CS_Character    *MC;

    MC = scene->QueryMC();
    if (MC->verifyAnimationEnd())
    {
        if (table->jump & KeyPress)
            MC->useJump();
        else if (table->att & KeyPress)
        {
            useAttack(scene);
        }
        else if (table->dodge & KeyPress)
            MC->swapMC();
        else if (table->right & KeyHoldPress || table->left & KeyHoldPress)
            walkMC(MC);
        else
            MC->loadAnimation(STATIC);
    }
    if (table->left & KeyHoldPress)
        MC->setRight(false);
    if (table->right & KeyHoldPress)
        MC->setRight(true);
}