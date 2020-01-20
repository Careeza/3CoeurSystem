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
            MC->loadAnimation(JUMP);
        else
            MC->loadAnimation(FALL);

    }
}

void    useAction(t_action *table, CS_Character *MC)
{
    if (MC->verifyAnimationEnd())
    {
        if (table->jump & KeyPress)
            MC->useJump();
        else if (table->att & KeyPress)
            MC->loadAnimation(ATTACK);
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