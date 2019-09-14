#ifndef EVENT_H

# define EVENT_H

# include "game.h"
  
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3
# define CLOSE 5

class		Event
{
	public:
	Event();
	void	QueryEvent();
	int		GestEvent();

	private:
	SDL_Event	event;
};

#endif
