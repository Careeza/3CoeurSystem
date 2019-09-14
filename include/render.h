#ifndef RENDER_H

# define RENDER_H

# include "texture.h"

class		Render
{
	public:
    Render();
    void	        init_renderer(Canvas canvas);
    SDL_Renderer	*Query_Renderer();
    void            add_texture_in_render(Texture texture);
    void            debug();
    void            aff_texture(Texture tex);
    void            aff_all();


	private:
    SDL_Renderer	        *rend;
    std::vector<Texture>    texture_list;
    int                     size;
};

#endif
