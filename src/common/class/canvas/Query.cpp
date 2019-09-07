#include "canvas.h"

	SDL_Renderer	*Canvas::Query_Renderer()
    {
        return (rend);
    }
	
    SDL_Window		*Canvas::Query_Window()
    {
        return (win);
    }