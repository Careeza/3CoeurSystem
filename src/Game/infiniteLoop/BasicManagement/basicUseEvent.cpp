#include "game.h"

bool    basicUseEvent(t_action action)
{
    if (action.escape == KeyPress)
        return (true);
    return (false);
}