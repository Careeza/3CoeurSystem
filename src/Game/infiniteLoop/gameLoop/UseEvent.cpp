#include "game.h"

void    gameGetEvenement(CS_Scene *scene, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl   event;


    while (event.loadEvenement(scene))
    {
        event.fillActionTable(actionTable, value);
    }
}

void    gameEventProcessing(t_actionTable *actionTable, t_action *action)
{
    CS_KeyControl::transformActionTable(actionTable);
    CS_KeyControl::resetAction(action);
    action->escape = actionTable->escape;
    action->att = actionTable->att;
    if ((actionTable->right & KeyHoldPress) && (actionTable->left & KeyReleaseNoPress))
        action->right = actionTable->right;
    if ((actionTable->left & KeyHoldPress) && (actionTable->right & KeyReleaseNoPress))
        action->left = actionTable->left;
    action->dodge = actionTable->dodge;
    action->jump = actionTable->jump;
}

void    walkMC(CS_Character *MC)
{
    if (MC->verifyOnGround())
    {
        MC->loadAnimation(WALK);
    }
    else
    {
        MC->loadAnimation(JUMP);
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