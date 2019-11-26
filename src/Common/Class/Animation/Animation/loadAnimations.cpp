# include "gameScene.h"

void    CS_Animation::newAnimation(t_animation nameSource, int stop)
{
    name = nameSource;
    interrupt = stop;
}


void    CS_Animation::loadTexture(SDL_Renderer *render, std::string png_left, std::string png_right)
{
    SDL_Surface *surface;

    surface = IMG_Load(png_left.c_str());
    if (!surface)
    {
        Tools->verbose(LEVEL1, "ss", "error creating surface (cs_animation) PNG =", png_left.c_str());
        exit (0);
    }
    textureL = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);

    surface = IMG_Load(png_right.c_str());
    if (!surface)
    {
        Tools->verbose(LEVEL1, "ss", "error creating surface 2 (cs_animation) PNG =", png_right.c_str());
        exit (0);
    }
    textureR = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

void        CS_Animation::cutFrame(int nb_frame, int nb_columnframe, int nb_lineframe)
{
    int         i;
    int         width;
    int         height;
    int         frameWidth;
    int         frameHeight;
    SDL_Rect    *newFrame;

    i = 0;
    SDL_QueryTexture (textureL, NULL, NULL, &width, &height);
    frameWidth = width / nb_columnframe;
    frameHeight = height / nb_lineframe;
    nbFrame = nb_frame;
    nbColumnFrame = nb_columnframe;
    nbLineFrame = nb_lineframe;
    frame.resize(nb_frame);
    while (i < nb_frame)
    {
        newFrame = new (SDL_Rect);
        frame[i] = newFrame;
        frame[i]->w = frameWidth;
        frame[i]->h = frameHeight;
        frame[i]->x = frameWidth * (i % nb_columnframe);
        frame[i]->y = frameHeight * (i / nb_columnframe);
        i++;
    }
}

void        CS_Animation::setMovement(int nb_frame, ...)
{
    va_list op;
    int     i;

    i = 0;
    va_start(op, nb_frame);
    movement.resize(nb_frame);
    while (i < nb_frame)
    {
        movement[i] = Tools->transformX((float)va_arg(op, double));
        i++;
    }
    va_end(op);
}
