#include "keyControl.h"

t_keyManagement    transform(t_keyManagement& save, t_keyManagement& transform)
{
    if (save == transform)
    {
        if (save == KeyPress)
        {
            transform = KeyHold;
            return (KeyHold);
        }
        else
        {
            transform = KeyNoPress;
            return (KeyNoPress);
        }
    }
    else
    {
        if (save == KeyPress)
        {
            if (transform != KeyHold)
            {
                transform = KeyPress;
                return (KeyPress);
            }
            return (KeyHold);
        }
        else
        {
            if (transform != KeyNoPress)
            {
                transform = KeyRelease;
                return (KeyRelease);
            }
            return (KeyNoPress);
        }
    }
}

void    transformActionTable(t_actionTable *table)
{
    transform(table->upSave, table->up);
    transform(table->downSave, table->down);
    transform(table->rightSave, table->right);
    transform(table->leftSave, table->left);
    transform(table->jumpSave, table->jump);
    transform(table->dodgeSave, table->dodge);
    transform(table->att_spSave, table->att_sp);
    transform(table->useSave, table->use);
    transform(table->spell_1Save, table->spell_1);
    transform(table->spell_2Save, table->spell_2);
}