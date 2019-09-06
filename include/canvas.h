#ifndef CANVAS_H

# define CANVAS_H

# include "common.h"

# define FULL_SCREEN 1
# define WINDOW 2

class		Canvas
{
	public:
	Canvas();
	void	init(int flags);
	void	create_window(int flags, int x = 0, int y = 0, int w = 0, int h = 0);
	bool	window_closed();
	void	close_window();

	private:
	bool		close_requested;
	SDL_Window	*win;
};

#endif
