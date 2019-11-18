#include "timer.h"

CS_Timer::CS_Timer()
{
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void CS_Timer::start()
{
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
}

void CS_Timer::stop()
{
    started = false;
    paused = false;
}

int CS_Timer::get_ticks()
{
    if (started == true)
    {
        if (paused == true)
            return pausedTicks;
        else
            return SDL_GetTicks() - startTicks;
    }
    return 0;
}

void CS_Timer::pause()
{
    if (started == true && paused == false)
    {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void CS_Timer::unpause()
{
    if (paused == true)
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

bool CS_Timer::is_started()
{
    return started;
}

bool CS_Timer::is_paused()
{
    return paused;
}