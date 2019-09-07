#include "texture.h"

Texture::Texture(Canvas canvas)
{
	rect = new SDL_Rect;
	frame = new SDL_Rect;
	
	
	rect = NULL;
	frame = NULL;
}

bool		Texture::load_surface(std::string route)
{
	surface = IMG_Load(route.c_str());
	if (!surface)
	{
		printf("error creating surface : %s\n", SDL_GetError());
		return (false);
	}
	return (true);
}

bool		Texture::load_texture(std::string route, Canvas canvas)
{
	surface = IMG_Load(route.c_str());
	if (!surface)
	{
		printf("error creating surface : %s\n", SDL_GetError());
		return (false);
	}
	tex = SDL_CreateTextureFromSurface(canvas.Query_Renderer(), surface);
	SDL_FreeSurface(surface);
	if (!tex)
	{
		printf("error creating texture: %s\n", SDL_GetError());
		return (false);
	}
	return (true);
}


void		Texture::resize_texture(int w, int h, int x, int y)
{
	rect->w = w;
	rect->h = h;
	rect->x = x;
	rect->y = y;
}

void		Texture::aff(Canvas canvas)
{
	SDL_RenderCopy(canvas.Query_Renderer(), tex, frame, rect);
}
