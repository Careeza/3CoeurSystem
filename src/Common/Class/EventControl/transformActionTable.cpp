#include "keyControl.h"

void    transform(t_keyManagement& save, t_keyManagement& transform)
{
    if (save == transform)
    {
        if (save == KeyPress)
            transform = KeyHold;
        else
            transform = KeyNoPress;
    }
    else
    {
        if (save == KeyPress)
        {
            if (transform != KeyHold)
            {
                transform = KeyPress;
            }
        }
        else
        {
            if (transform != KeyNoPress)
                transform = KeyRelease;
        }
    }
}

void    CS_KeyControl::transformActionTable(t_actionTable *table)
{
    transform(table->upSave, table->up);
    transform(table->downSave, table->down);
    transform(table->rightSave, table->right);
    transform(table->leftSave, table->left);
    transform(table->jumpSave, table->jump);
    transform(table->dodgeSave, table->dodge);
    transform(table->attSave, table->att);
    transform(table->att_spSave, table->att_sp);
    transform(table->useSave, table->use);
    transform(table->spell_1Save, table->spell_1);
    transform(table->spell_2Save, table->spell_2);
    transform(table->escapeSave, table->escape);
}