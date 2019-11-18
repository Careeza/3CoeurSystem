#include "tools.h"

CS_Tools::CS_Tools()
{
    debug = LEVEL0
    windowWidth = 0;
    windowHeight = 0;
    resolution = 0;
}

CS_Tools::~CS_Tools()
{

}

void    CS_Tools::getWindowSize(int w, int h)
{
    windowWidth = w;
    windowHeight = h;
    resolution = windowWidth / (float)windowHeight;
}

void    CS_Tools::debugMode(t_debug debugSource)
{
    debug = debugSource;
}