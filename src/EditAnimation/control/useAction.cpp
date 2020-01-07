#include "editAnimation.h"

void    resetAction(t_action *table)
{
    table->up = KeyNoPress;
    table->down = KeyNoPress;
    table->right = KeyNoPress;
    table->left = KeyNoPress;
    table->jump = KeyNoPress;
    table->dodge = KeyNoPress;
    table->att = KeyNoPress;
    table->att_sp = KeyNoPress;
    table->use = KeyNoPress;
    table->spell_1 = KeyNoPress;
    table->spell_2 = KeyNoPress;
}

void    fillAction(t_actionTable *table, t_action *action)
{
    resetAction(action);
//    std::cout << "reset" << std::endl;


    if (table->right & KeyHoldPress)
    if ((table->right & KeyHoldPress) && !(table->left & KeyHoldPress))
        action->right = table->right;
    if ((table->left & KeyHoldPress) && !(table->right & KeyHoldPress))
        action->left = table->left;
    action->dodge = table->dodge;
    action->jump = table->jump;
}


void    useAction2(t_action *table, CS_EditAnimationSetting& settings)
{
    (void)table;
    (void)settings;
}