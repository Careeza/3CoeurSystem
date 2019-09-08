#ifndef TEXTURE_H

# define TEXTURE_H

# include "pixel.h"
# include "canvas.h"

class		Texture
{
	public:
	Texture();
    bool    	load_surface(std::string route);
    bool    	load_texture(std::string route, SDL_Renderer *render, Canvas canvas);
	void		Query_Texture_Size(int *w, int *h);
	void		resize_texture(Canvas canvas, float w = 100, float h = 100, float x = 0, float y = 0);
	void		set_z_index(int couche);
	SDL_Rect	*Query_Rect();
	SDL_Rect	*Query_Frame();
	SDL_Texture	*Query_Texture();
	int			Query_z_Index();
//	void	aff(Canvas canvas);

	protected:
    SDL_Rect        *rect;
	SDL_Rect		*frame;
	SDL_Surface 	*surface;
	SDL_Texture		*tex;
	int				z_index;
};

class		Animation : public Texture
{
	public:
	Animation(int nb_column, int nb_line);
	void	load_animation(std::string route, SDL_Renderer *render, Canvas canvas);
	void	launch_animation();
	
	void	debug();

	private:
	std::vector<int>	frame_x;
	std::vector<int>	frame_y;
	int 				column;
	int 				line;
	int					nb_frames;
	int					current_frame;
	bool				end;
};

#endif
