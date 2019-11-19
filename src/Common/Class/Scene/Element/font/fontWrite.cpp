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
    if (texte.compare("") != 0)
        ratio = w / (float)h;
//    std::cout << ratio << std::endl;
    div_w = size->w - (2 * CS_marginX);
    div_h = size->h - (2 * CS_marginY);
    div_x = size->x + CS_marginX;
    div_y = size->y + CS_marginY - ((float)div_h / 12);
//    std::cout << "div = " << div_h << " -- " << div_y << " whithout margin " << size->h << " -- "<< size->y << std::endl;
    CS_size->h = div_h;
    if (texte.compare("") != 0)
        CS_size->w = CS_size->h * ratio;
    else
    {
        std::cout << "lolipop" << std::endl;
        CS_size->w = 0;
    }
    CS_size->y = div_y;
    if (CS_size->w > div_w)
    {
        std::cout << "texte trop long " << size->w << std::endl;
        exit (0);
    }
    if (CS_flags == ALIGN_CENTER)
    {
//        std::cout << "center" << std::endl;
        CS_size->x = (div_x + (div_w) / 2) - (CS_size->w / 2);
//        std::cout << CS_size->x << " -- " << div_x + div_h << std::endl;
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

void    CS_Police::CS_writeTexteScaleW(std::string texte, SDL_Rect *size, SDL_Renderer *render)
{
    int     w;
    int     h;
    float   ratio;

    surface = TTF_RenderText_Blended(CS_font, texte.c_str(), CS_color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_FreeSurface(surface);
    if (texte.compare("") != 0)
        ratio = h / (float)w;
    div_w = size->w - (2 * CS_marginX);
    div_h = size->h - (2 * CS_marginY);
    div_x = size->x + CS_marginX + ((float)div_w / 64);
    div_y = size->y + CS_marginY - ((float)div_h / 12);
    CS_size->w = div_w;
    if (texte.compare("") != 0)
        CS_size->h = CS_size->w * ratio;
    else
        CS_size->h = 0;        
    CS_size->y = div_y + (div_h / 2) - (CS_size->h / 2);
    CS_size->x = div_x;
}

/*void            CS_Police::changeText(std::string texte, SDL_Rect *size, SDL_Renderer *render);
{
    SDL_DestroyTexture(texture);
    CS_writeTexte(texte, size, render);
}*/

void            CS_Police::CS_zoomText(int zoomInfo)
{
    zoom = zoomInfo;
//    std::cout << "change zoom - " << zoom << std::endl;
}