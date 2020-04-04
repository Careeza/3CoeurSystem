#include "action.h"

CS_Game::CS_Game()
{

}

CS_Game::~CS_Game()
{

}

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

bool            CS_Game::start()
{
    SDL_Renderer    *render;
    int w;
    int h;

    window = create_window(SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_GetWindowSize(window, &w, &h);

    windowRatioW = 1920 / (float)w;
    windowRatioH = 1080 / (float)h;

    render = init_renderer(window);
    this->render.loadRenderer(render);

    CS_KeyControl::fillActionValue(&value);

}

void            CS_Game::addToRenderList(s_RenderElement renderElement)
{

}

t_actionValue   &CS_Game::QueryValue()
{
    return(value);
}

t_actionTable   &CS_Game::QueryAction()
{
    return(action);
}

CS_Render       &CS_Game::QueryRender()
{
    return(render);
}

CS_GamePhysics  &CS_Game::QueryGamePhysics()
{
    return(gamePhysic);
}

SDL_Window      *CS_Game::QueryWindow()
{
    return(window);
}

CS_Game     game;
float       windowRatioW;
float       windowRatioH;