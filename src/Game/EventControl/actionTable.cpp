#include "game.h"

void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info)
{
    if (info == CS_KEYDOWN)
    {
        if (value->up == key)
            table->up = true;
        else if (value->down == key)
            table->down = true;
        else if (value->right == key)
            table->right = true;
        else if (value->left == key)
            table->left = true;
        else if (value->jump == key)
            table->jump = true;
        else if (value->dodge == key)
            table->dodge = true;
        else if (value->att == key)
            table->att = true;
        else if (value->att_sp == key)
            table->att_sp = true;
        else if (value->use == key)
            table->use = true;
        else if (value->spell_1 == key)
            table->spell_1 = true;
        else if (value->spell_2 == key)
            table->spell_2 = true;
    }
    else if (info == CS_KEYUP)
    {
        if (value->up == key)
            table->up = false;
        else if (value->down == key)
            table->down = false;
        else if (value->right == key)
            table->right = false;
        else if (value->left == key)
            table->left = false;
        else if (value->jump == key)
            table->jump = false;
        else if (value->dodge == key)
            table->dodge = false;
        else if (value->att == key)
            table->att = false;
        else if (value->att_sp == key)
            table->att_sp = false;
        else if (value->use == key)
            table->use = false;
        else if (value->spell_1 == key)
            table->spell_1 = false;
        else if (value->spell_2 == key)
            table->spell_2 = false;
    }
    else
    {}
}

void    filtreActionTable(t_actionTable *table, t_actionTable *filtre)
{
    resetActionTable(filtre);
//    std::cout << "reset" << std::endl;
    if (table->right & !table->left)
        filtre->right = true;
    if (table->left & !table->right)
        filtre->left = true;
    filtre->dodge = table->dodge;
}