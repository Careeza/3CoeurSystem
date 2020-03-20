# include "tools.h"


void	init(int flags)
{
	if (SDL_Init(flags) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		exit (0);
	}
}

SDL_Window  *create_window(int flags, const std::string name, int x, int y, int w, int h)
{
    SDL_Window  *window;

	window = SDL_CreateWindow(name.c_str(), x, y, w, h, flags);
	if (!window)
	{
		printf("error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		exit (0);
	}
    return (window);
}

SDL_Renderer    *init_renderer(SDL_Window    *window)
{
    Uint32          render_flags;
    SDL_Renderer    *render;

    render_flags = SDL_RENDERER_ACCELERATED;
    render = SDL_CreateRenderer(window, -1, render_flags);
	if (!render)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
        exit (0);
	}
    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    return (render);
}
