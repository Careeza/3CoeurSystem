#include "keyControl.h"

void    useAction(t_actionTable *table)
{
    CS_Character    *MC;

    MC = gameSettings.gameScene->CS_queryMC();
    if (table->right == true)
    {
        std::cout << "load animation STATIC !" << std::endl;
        MC->loadAnimation(STATIC);
        MC->setRight(true);
    }
    else if (table->left == true)
    {
        std::cout << "load animation STATIC !" << std::endl;
        MC->loadAnimation(STATIC);
        MC->setRight(false);
    }
    else
    {
        std::cout << "load animation STATIC !" << std::endl;
        MC->loadAnimation(STATIC);
    }
//        std::cout << "no moove" << std::endl;
}

void    actionKeyManagement(CS_KeyControl event, t_actionValue *value)
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
    useAction(&filtre);
}