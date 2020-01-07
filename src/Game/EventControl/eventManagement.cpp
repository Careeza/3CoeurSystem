#include "game.h"

void    eventManagement(CS_Settings& settings, SDL_Renderer *rend, t_actionValue *value, t_actionTable *actionTable, t_action *action)
{
    CS_KeyControl   event;

    while (event.loadEvenement(settings.QueryScene()))
    {
        if (settings.QueryPosition() & (homeHome | menuMenu))
            bouttonManagement(event, settings, rend);
        if (settings.QueryPosition() == game)
        {
            actionKeyManagement(event, value, actionTable, action);
        }
        escapeKeyManagement(event, settings, rend);
    }
}
