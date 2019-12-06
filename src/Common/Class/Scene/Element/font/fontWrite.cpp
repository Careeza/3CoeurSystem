# include "scene.h"

void    CS_Police::writeTexte(std::string texte, SDL_Rect *sizeSource, SDL_Renderer *render)
{
    int     w;
    int     h;
    float   ratio;

    surface = TTF_RenderText_Blended(font, texte.c_str(), color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    if (texture == NULL)
        std::cout << "error LUL" << std::endl;
    haveTexture = true;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_FreeSurface(surface);
    if (texte.compare("") != 0)
        ratio = w / (float)h;
//    std::cout << ratio << std::endl;
    div_w = sizeSource->w - (2 * marginX);
    div_h = sizeSource->h - (2 * marginY);
    div_x = sizeSource->x + marginX;
    div_y = sizeSource->y + marginY - ((float)div_h / 12);
//    std::cout << "div = " << div_h << " -- " << div_y << " whithout margin " << size->h << " -- "<< size->y << std::endl;
    size->h = div_h;
    if (texte.compare("") != 0)
        size->w = size->h * ratio;
    else
    {
        std::cout << "lolipop" << std::endl;
        size->w = 0;
    }
    size->y = div_y;
    if (size->w > div_w)
    {
        std::cout << "texte trop long " << size->w << std::endl;
        exit (0);
    }
    if (flags == ALIGN_CENTER)
    {
//        std::cout << "center" << std::endl;
        size->x = (div_x + (div_w) / 2) - (size->w / 2);
//        std::cout << CS_size->x << " -- " << div_x + div_h << std::endl;
    }
    else if (flags == ALIGN_LEFT)
    {
        size->x = div_x;
    }
    else if (flags == ALIGN_RIGHT)
    {
        size->x = (div_x + div_h) - size->w;
    }
    else
    {
        std::cout << "wrong flag" << std::endl;
        exit (0);
    }
}

void    CS_Police::writeTexteScaleW(std::string texte, SDL_Rect *sizeSource, SDL_Renderer *render)
{
    int     w;
    int     h;
    float   ratio;

    surface = TTF_RenderText_Blended(font, texte.c_str(), color);
    texture = SDL_CreateTextureFromSurface(render, surface);
    haveTexture = true;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_FreeSurface(surface);
    if (texte.compare("") != 0)
        ratio = h / (float)w;
    div_w = sizeSource->w - (2 * marginX);
    div_h = sizeSource->h - (2 * marginY);
    div_x = sizeSource->x + marginX + ((float)div_w / 64);
    div_y = sizeSource->y + marginY - ((float)div_h / 12);
    size->w = div_w;
    if (texte.compare("") != 0)
        size->h = size->w * ratio;
    else
        size->h = 0;        
    size->y = div_y + (div_h / 2) - (size->h / 2);
    size->x = div_x;
}

void            CS_Police::changeText(std::string texte, SDL_Rect *size, SDL_Renderer *render)
{
    SDL_DestroyTexture(texture);
    writeTexte(texte, size, render);
}

void            CS_Police::zoomText(int zoomInfo)
{
    zoom = zoomInfo;
//    std::cout << "change zoom - " << zoom << std::endl;
}