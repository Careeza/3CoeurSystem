#ifndef TIMER_H

# define TIMER_H

# include "game.h"

class CS_Timer
{
    private:
    int startTicks;
    int pausedTicks;

    bool paused;
    bool started;

    public:
    CS_Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();

    bool is_started();
    bool is_paused();
};

#endif