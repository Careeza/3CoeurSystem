#include "texture.h"

void            Texture::Query_Texture_Size(int *w, int *h)
{
    SDL_QueryTexture(tex, NULL, NULL, w, h);
}

SDL_Texture     *Texture::Query_Texture()
{
    return (tex);
}

int             Texture::Query_z_Index()
{
    return (z_index);
}

SDL_Rect	    *Texture::Query_Rect()
{
    return (rect);
}

SDL_Rect	    *Texture::Query_Frame()
{
    return (frame);
}