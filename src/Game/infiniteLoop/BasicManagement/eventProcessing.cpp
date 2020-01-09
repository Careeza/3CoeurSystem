#include "game.h"

void    homeEventProcessing(t_actionTable *actionTable, t_action *action)
{
    CS_KeyControl::transformActionTable(actionTable);
    CS_KeyControl::resetAction(action);
    action->escape = actionTable->escape;
    action->att = actionTable->att;
}