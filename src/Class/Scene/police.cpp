# include "scene.h"

CS_Police::CS_Police()
{
    CS_size = new (SDL_Rect);
    CS_flags = ALIGN_CENTER;
    CS_marginX = 5;
    CS_marginY = 5;
}

CS_Police::~CS_Police()
{
    delete CS_size;
    SDL_DestroyTexture(texture);
}

void    CS_Police::CS_initPolice(std::string police)
{
    std::cout << "init police" << std::endl;
    CS_font = TTF_OpenFont(police.c_str(), 40);
    if (CS_font == NULL)
        std::cout << "error init police" << std::endl;
}

void    CS_Police::affInfoForLouis()
{
    if (CS_font == NULL)
        std::cout << "no font and test = " << std::endl;
    else
        std::cout << "have a font and test = " << std::endl;
}

void    CS_Police::CS_policeSetting(CS_Color color, int flags, int marginX, int marginY)
{
    CS_flags = flags;
    CS_marginX = marginX;
    CS_marginY = marginY;
    CS_color.r = color.CS_queryRed();
    CS_color.g = color.CS_queryGreen();
    CS_color.b = color.CS_queryBlue();
    CS_color.a = color.CS_queryAlpha();
}

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


SDL_Texture     *CS_Police::CS_queryTexte()
{
    return (texture);
}

SDL_Rect        *CS_Police::querySize()
{
    return (CS_size);
}