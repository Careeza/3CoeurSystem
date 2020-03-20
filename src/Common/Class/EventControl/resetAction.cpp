#include "keyControl.h"

void    CS_KeyControl::resetAction(t_action *table)
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
    table->escape = KeyNoPress;
}
