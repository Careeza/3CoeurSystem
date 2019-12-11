#include "game.h"

void    useAction(t_actionTable *table, CS_Settings& settings)
{
    CS_Character    *MC;

    MC = settings.QueryGameScene()->QueryMC();
    if (table->right == true)
    {
        if (table->dodge == true)
            MC->loadAnimation(SPRINT);
        else
            MC->loadAnimation(WALK);
        MC->setRight(true);
    }
    else if (table->left == true)
    {
        if (table->dodge == true)
            MC->loadAnimation(SPRINT);
        else
            MC->loadAnimation(WALK);
        MC->setRight(false);
    }
    else
        MC->loadAnimation(STATIC);
}

void    useAction2(t_actionTable *table, CS_Settings& settings)
{
    CS_Camera    *camera;

    camera = settings.QueryGameScene()->QueryCamera();
    if (table->right == true)
        camera->moveCamera2(5, 0, settings.QueryGameScene());
    else if (table->left == true)
        camera->moveCamera2(-5, 0, settings.QueryGameScene());
    else
        ;
//        std::cout << "No press" << std::endl;
}

void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, t_actionTable *action)
{
    int                     key;
    int                     info;
    static t_actionTable    table;
    static int              i = 0;
 
    if (i == 0)
    {
        resetActionTable(&table);
        i++;
    }
    info = event.getKeyboardActions(key);
    fillActionTable(&table, value, key, info);
    filtreActionTable(&table, action);
}