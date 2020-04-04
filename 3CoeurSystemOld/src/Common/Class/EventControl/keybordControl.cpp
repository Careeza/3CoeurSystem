#include "keyControl.h"

int     CS_KeyControl::getKey()
{
    return (event.key.keysym.sym);
}
