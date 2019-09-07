#include "canvas.h"

void    Canvas::init_renderer()
{
    Uint32          render_flags;

    render_flags = render_flags = SDL_RENDERER_ACCELERATED;
    rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
        exit (0);
	}
}