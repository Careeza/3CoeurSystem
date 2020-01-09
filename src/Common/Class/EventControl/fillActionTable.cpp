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
    else if (value->att == key)
        table->attSave = KeyPress;
    else if (value->att_sp == key)
        table->att_spSave = KeyPress;
    else if (value->use == key)
        table->useSave = KeyPress;
    else if (value->spell_1 == key)
        table->spell_1Save = KeyPress;
    else if (value->spell_2 == key)
        table->spell_2Save = KeyPress;
    else if (value->escape == key)
        table->escapeSave = KeyPress;
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
    else if (value->att == key)
        table->attSave = KeyRelease;
    else if (value->att_sp == key)
        table->att_spSave = KeyRelease;
    else if (value->use == key)
        table->useSave = KeyRelease;
    else if (value->spell_1 == key)
        table->spell_1Save = KeyRelease;
    else if (value->spell_2 == key)
        table->spell_2Save = KeyRelease;
    else if (value->escape == key)
        table->escapeSave = KeyRelease;
}

void    CS_KeyControl::fillActionTable(t_actionTable *table, t_actionValue *value)
{
    if (type == SDL_KEYDOWN)
        fillPress(table, value, getKey());
    else if (type == SDL_KEYUP)
        fillNoPress(table, value, getKey());
    if (type == SDL_MOUSEBUTTONDOWN)
        fillPress(table, value, getButton());
    else if (type == SDL_MOUSEBUTTONUP)
        fillNoPress(table, value, getButton());
}