#include "tools.h"

int     CS_Tools::modulo(int a, int b)
{
    int res;

    res = a % b;
    while (res < 0)
        res += b;
    return (res);
}
