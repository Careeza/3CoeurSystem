#include "keyControl.h"

void    fillActionValue(t_actionValue *value)
{
    value->up = SDLK_z;
    value->down = SDLK_s;
    value->right = SDLK_d;
    value->left = SDLK_q;
    value->jump = SDLK_SPACE;
    value->dodge = SDLK_LSHIFT;
    value->att = -1;
    value->att_sp = -1;
    value->use = SDLK_f;
    value->spell_1 = SDLK_a;
    value->spell_2 = SDLK_e;
}

void    resetActionTable(t_actionTable *table)
{
    table->up = false;
    table->down = false;
    table->right = false;
    table->left = false;
    table->jump = false;
    table->dodge = false;
    table->att = false;
    table->att_sp = false;
    table->use = false;
    table->spell_1 = false;
    table->spell_2 = false;
}