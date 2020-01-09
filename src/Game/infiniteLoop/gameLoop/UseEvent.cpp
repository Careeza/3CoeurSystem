#include "game.h"

t_pos   gameUseEvent(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    if (action.escape == KeyPress)
    {
        render->saveScreen();
        if (loopMenu(render, value, actionTable))
            return (home);
        else
            return (game);
    }
    return (game);
}

void    useAction(t_action *table, CS_Character *MC, int deltaT)
{
    if (MC->verifyAnimationEnd())
    {
        if (table->jump & KeyPress)
            MC->QeuryPhysique()->setSpeedY(-1000);
        else if (table->att & KeyPress)
            MC->loadAnimation(ATTACK);
        else if (table->right & KeyHoldPress)
        {
            MC->setRight(true);
            MC->loadAnimation(WALK);
        }
        else if (table->left & KeyHoldPress)
        {
            MC->setRight(false);
            MC->loadAnimation(WALK);
        }
        else
            MC->loadAnimation(STATIC);
    }
}