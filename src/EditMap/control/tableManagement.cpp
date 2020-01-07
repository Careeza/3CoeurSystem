#include "editMap.h"

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