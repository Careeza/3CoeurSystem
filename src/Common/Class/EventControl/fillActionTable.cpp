#include "keyControl.h"

void    fillPress(t_actionTable *table, t_actionValue *value, int key)
{
    if (value->up == key)
        table->upSave = KeyPress;
    else if (value->down == key)
        table->downSave = KeyPress;
    else if (value->right == key)
        table->rightSave = KeyPress;
    else if (value->left == key)
        table->leftSave = KeyPress;
    else if (value->jump == key)
        table->jumpSave = KeyPress;
    else if (value->dodge == key)
        table->dodgeSave = KeyPress;
    else if (value->use == key)
        table->useSave = KeyPress;
    else if (value->spell_1 == key)
        table->spell_1Save = KeyPress;
    else if (value->spell_2 == key)
        table->spell_2Save = KeyPress;
}

void    fillNoPress(t_actionTable *table, t_actionValue *value, int key)
{
    if (value->up == key)
        table->upSave = KeyRelease;
    else if (value->down == key)
        table->downSave = KeyRelease;
    else if (value->right == key)
        table->rightSave = KeyRelease;
    else if (value->left == key)
        table->leftSave = KeyRelease;
    else if (value->jump == key)
        table->jumpSave = KeyRelease;
    else if (value->dodge == key)
        table->dodgeSave = KeyRelease;
    else if (value->use == key)
        table->useSave = KeyRelease;
    else if (value->spell_1 == key)
        table->spell_1Save = KeyRelease;
    else if (value->spell_2 == key)
        table->spell_2Save = KeyRelease;}

void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info)
{
    if (info == CS_KEYDOWN)
    {
        fillPress(table, value, key);
    }
    else if (info == CS_KEYUP)
    {
        fillNoPress(table, value, key);
    }
}

void    initActionTable(t_actionTable *table)
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
}