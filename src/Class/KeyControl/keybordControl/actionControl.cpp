#include "keyControl.h"

void    useAction(t_actionTable *table)
{
    if (table->right == true)
        std::cout << "turn right" << std::endl;
    else if (table->left == true)
        std::cout << "turn left" << std::endl;
//    else
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