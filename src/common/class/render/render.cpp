# include "render.h"
# include "texture.h"


Render::Render()
{
    size = 0;
}

void    Render::init_renderer(Canvas canvas)
{
    Uint32          render_flags;

    render_flags = render_flags = SDL_RENDERER_ACCELERATED;
    rend = SDL_CreateRenderer(canvas.Query_Window(), -1, render_flags);
	if (!rend)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(canvas.Query_Window());
		SDL_Quit();
        exit (0);
	}
}

void    Render::add_texture_in_render(Texture texture)
{
    int i = 0;

    while (i < size && texture.Query_z_Index() >= texture_list[i].Query_z_Index())
        i++;
    if (i == size)
        texture_list.push_back(texture);
    else
        texture_list.emplace(texture_list.begin() + i, texture);
    size++;
}

void    Render::aff_texture(Texture tex)
{
    SDL_RenderCopy(rend, tex.Query_Texture(), tex.Query_Frame(), tex.Query_Rect());
}

void    Render::aff_all()
{
    Texture tex;

    for (int i = 0 ; i < size ; i++)
        aff_texture(texture_list[i]);
}

void    Render::debug()
{
    std::cout << size << std::endl;
}