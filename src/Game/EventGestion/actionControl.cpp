#include "game.h"

void    useAction(t_actionTable *table, CS_Settings& settings)
{
    CS_Character    *MC;

    MC = settings.QueryGameScene()->CS_queryMC();
    if (table->right == true)
    {
        if (table->dodge == true)
        {
            MC->loadAnimation(SPRINT);
        }
        else
        {
            MC->loadAnimation(WALK);
        }
        MC->setRight(true);
    }
    else if (table->left == true)
    {
        if (table->dodge == true)
        {
            MC->loadAnimation(SPRINT);
        }
        else
        {
            MC->loadAnimation(WALK);
        }
        MC->setRight(false);
    }
    else
    {
//        std::cout << "load animation STATIC !" << std::endl;
        MC->loadAnimation(STATIC);
    }
//        std::cout << "no moove" << std::endl;
}

void    useAction2(t_actionTable *table, CS_Settings& settings)
{
    CS_Camera    *camera;

    camera = settings.QueryGameScene()->QueryCamera();
    if (table->right == true)
    {
        std::cout << "press" << std::endl;
        camera->moveCamera2(5, 0);
    }
    else if (table->left == true)
    {
        std::cout << "press" << std::endl;
        camera->moveCamera2(-5, 0);
    }
    else
    {
        std::cout << "No press" << std::endl;
    }
}

void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, CS_Settings& settings)
{
    int                     key;
    int                     info;
    static t_actionTable    table;
    static t_actionTable    filtre;
    static int              i = 0;
 
    if (i == 0)
    {
        resetActionTable(&table);
        resetActionTable(&filtre);
        i++;
    }
    info = event.CS_getKeyboardActions(key);
    fillActionTable(&table, value, key, info);
    filtreActionTable(&table, &filtre);
    useAction2(&filtre, settings);
}