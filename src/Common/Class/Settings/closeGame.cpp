#include "common.h"

using namespace std;

void    closeGame(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getCloseRequest(true);
}