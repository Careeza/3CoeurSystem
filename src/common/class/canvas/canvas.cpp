#include "canvas.h"

Canvas::Canvas()
{
	close_requested = false;
}

void	Canvas::init(int flags)
{
	if (SDL_Init(flags) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		exit (0);
	}
}