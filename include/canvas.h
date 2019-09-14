#ifndef CANVAS_H

# define CANVAS_H

# include "game.h"

class		Canvas
{
	public:
	Canvas();
	void			init(int flags);
	void			create_window(int flags, const std::string& name = "canvas",
						 int x = 0, int y = 0, int w = 0, int h = 0);
	bool			window_closed();
	void			close_window();

	SDL_Window		*Query_Window();
	void			Query_Window_Size(int *w, int *h);

	private:
	bool			close_requested;
	SDL_Window		*win;
};

#endif
