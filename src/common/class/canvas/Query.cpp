#include "canvas.h"

    SDL_Window		*Canvas::Query_Window()
    {
        return (win);
    }

    void            Canvas::Query_Window_Size(int *w, int *h)
    {
        SDL_GetWindowSize(win, w, h);
    }
