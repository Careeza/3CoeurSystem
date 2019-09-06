#include "../../../include/event.h"

Event::Event()
{
}

void	Event::QueryEvent()
{
	SDL_PollEvent(&event);
}

int		Event::GestEvent()
{
	switch (event.type)
	{
		case SDL_QUIT:
			return (CLOSE);
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
				case SDL_SCANCODE_UP:
					return (UP);
				case SDL_SCANCODE_DOWN:
					return (DOWN);
				case SDL_SCANCODE_RIGHT:
					return (RIGHT);
				case SDL_SCANCODE_LEFT:
					return (LEFT);
				case SDL_SCANCODE_ESCAPE:
					return (CLOSE);
				default:
					break;
			}
		default:
			return (-1);
	}
}
