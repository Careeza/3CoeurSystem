#include "canvas.h"

bool	Canvas::window_closed()
{
	return (close_requested);
}

void	Canvas::close_window()
{
	close_requested = true;
}

void	Canvas::create_window(int flags, int x, int y, int w, int h)
{
	win = SDL_CreateWindow("PixelRPG", x, y, w, h, flags);
	if (!win)
	{
		printf("error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		exit (0);
	}
}

