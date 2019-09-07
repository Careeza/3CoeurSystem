#ifndef CANVAS_H

# define CANVAS_H

# include "pixel.h"

class		Canvas
{
	public:
	Canvas();
	void			init(int flags);
	void			create_window(int flags, const std::string& name = "canvas",
						 int x = 0, int y = 0, int w = 0, int h = 0);
	void			init_renderer();
	bool			window_closed();
	void			close_window();

	SDL_Renderer	*Query_Renderer();
	SDL_Window		*Query_Window();

	private:
	bool			close_requested;
	SDL_Window		*win;
	SDL_Renderer	*rend;
};

#endif
