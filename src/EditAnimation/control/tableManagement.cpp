#include "editAnimation.h"

void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, t_actionTable *actionTable, t_action *action)
{
    int                     key;
    int                     info;
 
    info = event.getKeyboardActions(key);
    fillActionTable(actionTable, value, key, info);
}