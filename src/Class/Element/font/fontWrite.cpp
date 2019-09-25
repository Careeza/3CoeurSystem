# include "scene.h"

void    CS_Police::CS_writeTexte(std::string texte, SDL_Rect *size, SDL_Renderer *render)
{
    int     w;
    int     h;
    float   ratio;

    surface = TTF_RenderText_Blended(CS_font, texte.c_str(), CS_color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_FreeSurface(surface);
    ratio = w / (float)h;
    std::cout << ratio << std::endl;
    div_w = size->w - (2 * CS_marginX);
    div_h = size->h - (2 * CS_marginY);
    div_x = size->x + CS_marginX;
    div_y = size->y - CS_marginX;
    std::cout << "div = " << div_h << " -- " << div_y << " whithout margin " << size->h << " -- "<< size->y << std::endl;
    CS_size->h = div_h;
    CS_size->w = CS_size->h * ratio;
    CS_size->y = div_y;
    if (CS_size->w > div_w)
    {
        std::cout << "texte trop long" << std::endl;
        exit (0);
    }
    if (CS_flags == ALIGN_CENTER)
    {
        std::cout << "center" << std::endl;
        CS_size->x = (div_x + (div_w) / 2) - (CS_size->w / 2);
        std::cout << CS_size->x << " -- " << div_x + div_h << std::endl;
    }
    else if (CS_flags == ALIGN_LEFT)
    {
        CS_size->x = div_x;
    }
    else if (CS_flags == ALIGN_RIGHT)
    {
        CS_size->x = (div_x + div_h) - CS_size->w;
    }
    else
    {
        std::cout << "wrong flag" << std::endl;
        exit (0);
    }
}