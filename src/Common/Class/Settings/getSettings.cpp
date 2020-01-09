#include "game.h"

void    CS_Settings::getWindowSize(int w, int h)
{
    windowWidth = w;
    windowHeight = h;
    resolution = w/(float)h;
}

void    CS_Settings::getCloseRequest(bool close)
{
    closeRequested = close;
}

void    CS_Settings::getPauseRequest(bool pause)
{
    pauseRequested = pause;
}

void    CS_Settings::getFps(int fpsSource)
{
    fps = fpsSource;
}