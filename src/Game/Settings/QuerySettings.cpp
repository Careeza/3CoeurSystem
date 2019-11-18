#include "game2.h"

int     CS_Settings::QueryWindowsWidth()
{
    return (windowWidth);
}

int     CS_Settings::QueryWindowsHeight()
{
    return (windowHeight);
}

float   CS_Settings::QueryWindowsResolution()
{
    return (resolution);
}

bool    CS_Settings::QueryCloseRequest()
{
    return (closeRequested);
}

bool    CS_Settings::QueryPauseRequest()
{
    return (pauseRequested);
}

int     CS_Settings::QueryFps()
{
    return (fps);
}

t_pos   CS_Settings::QueryPosition()
{
    return (pos)
}