#include "keyControl.h"

void    CS_KeyControl::fillActionValue(t_actionValue *value)
{
    value->up = SDLK_z;
    value->down = SDLK_s;
    value->right = SDLK_d;
    value->left = SDLK_q;
    value->jump = SDLK_SPACE;
    value->dodge = SDLK_LSHIFT;
    value->att = SDL_BUTTON_LEFT;
    value->att_sp = SDL_BUTTON_RIGHT;
    value->use = SDLK_f;
    value->spell_1 = SDLK_a;
    value->spell_2 = SDLK_e;
    value->escape = SDLK_ESCAPE;
}
