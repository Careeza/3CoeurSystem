#include "game.h"

void    fillAction(t_actionTable *table, t_action *action)
{
    resetAction(action);
//    std::cout << "reset" << std::endl;

    action->right = table->right;
    action->left = table->left;
    action->dodge = table->dodge;
    action->jump = table->jump;
}