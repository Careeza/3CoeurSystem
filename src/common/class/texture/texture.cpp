#include "texture.h"

Texture::Texture()
{
	z_index = 0;
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

bool		Texture::load_texture(std::string route, SDL_Renderer *render)
{
	surface = IMG_Load(route.c_str());
	if (!surface)
	{
		printf("error creating surface : %s\n", SDL_GetError());
		return (false);
	}
	tex = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
	if (!tex)
	{
		printf("error creating texture: %s\n", SDL_GetError());
		return (false);
	}
	return (true);
}


void		Texture::resize_texture(Canvas canvas, float w, float h, float x, float y)
{
	int	windos_w;
	int windos_h;

	canvas.Query_Window_Size(&windos_w, &windos_h);
	/*if (debug == true)
	{
		if (w > 100 || w < 0 
			|| h > 100 || h < 0
			|| x > 100 || x < 0
			|| y > 100 || y < 0)
		{
			std::cout << "Programe exit : wrong size for texture" << std::endl;
			exit (0);
		}
	}*/
	rect->w = windos_w * (w / 100.0);
	rect->h = windos_h * (h / 100.0);
	rect->x = windos_w * (x / 100.0);
	rect->y = windos_h * (y / 100.0);
}

void		Texture::set_z_index(int couche)
{
	z_index = couche;
}