#include "game.h"

void    goToRight(CS_Character *MC, bool right)
{
    MC->setRight(right);
    MC->loadAnimation(WALK);
}

void    directionSet(t_action *table, CS_Character *MC)
{
    if (table->right & KeyPressRelease)
    {
        if (table->right & KeyPress)
            goToRight(MC, true);
        else
        {
            if (table->left & KeyHoldPress)
                goToRight(MC, false);
            else
                MC->loadAnimation(STATIC);
        }
    }
    else if (table->left & KeyPressRelease)
    {
        if (table->left & KeyPress)
            goToRight(MC, false);
        else
        {
            if (table->right & KeyHoldPress)
                goToRight(MC, true);
            else
                MC->loadAnimation(STATIC);
        }
    }
}

void    useAction(t_action *table, CS_Settings& settings, int deltaT)
{
    CS_Character        *MC;

    MC = settings.QueryGameScene()->QueryMC();
    MC->updateFrame(deltaT);
    if ((table->right & KeyPressRelease) || (table->left & KeyPressRelease))
        directionSet(table, MC);
    if (table->jump & KeyPress)
        MC->QeuryPhysique()->setSpeedY(-1000);
}

void    useAction2(t_action *table, CS_Settings& settings)
{
    CS_Camera    *camera;

    camera = settings.QueryGameScene()->QueryCamera();
    if (table->right & KeyHoldPress)
        camera->moveCamera2(5, 0, settings.QueryGameScene());
    else if (table->left & KeyHoldPress)
        camera->moveCamera2(-5, 0, settings.QueryGameScene());
    else
        ;
//        std::cout << "No press" << std::endl;
}

void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, t_actionTable *actionTable, t_action *action)
{
    int                     key;
    int                     info;
 
    info = event.getKeyboardActions(key);
    fillActionTable(actionTable, value, key, info);
}