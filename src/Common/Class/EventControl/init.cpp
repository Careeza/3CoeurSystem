#include "keyControl.h"

void    CS_KeyControl::initActionTable(t_actionTable *table)
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

    table->upSave = KeyNoPress;
    table->downSave = KeyNoPress;
    table->rightSave = KeyNoPress;
    table->leftSave = KeyNoPress;
    table->jumpSave = KeyNoPress;
    table->dodgeSave = KeyNoPress;
    table->attSave = KeyNoPress;
    table->att_spSave = KeyNoPress;
    table->useSave = KeyNoPress;
    table->spell_1Save = KeyNoPress;
    table->spell_2Save = KeyNoPress;
    table->escape = KeyNoPress;
}