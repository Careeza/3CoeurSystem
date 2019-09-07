#ifndef TEXTURE_H

# define TEXTURE_H

# include "pixel.h"
# include "canvas.h"

class		Texture
{
	public:
	Texture();
    bool    load_surface(std::string route);
    bool    load_texture(std::string route, Canvas canvas);
	void	resize_texture(int w, int h, int x = 0, int y = 0);
	void	aff(Canvas canvas);

	private:
    SDL_Rect        *rect;
	SDL_Rect		*frame;
	SDL_Surface 	*surface;
	SDL_Texture		*tex;
};

#endif
