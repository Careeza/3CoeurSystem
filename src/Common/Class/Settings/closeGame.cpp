#include "common.h"

using namespace std;

void    closeGame(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    (void)render;
    set = (CS_Settings*)settings;
    set->getCloseRequest(true);
}