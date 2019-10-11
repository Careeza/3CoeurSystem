# include "gameScene.h"

CS_Animation    *initAnimation(std::string name)
{
    CS_Animation *animation;

    animation = new(CS_Animation);
    animation->name = name;
    return (animation);
}

void    loadTexture(CS_Animation *animation, SDL_Renderer *render, std::string png_left, std::string png_right)
{
    SDL_Surface *surface;

    surface = IMG_Load(png_left.c_str());
    if (!surface)
    {
        std::cout << "error creating surface 1 -> " << png_left << "." << std::endl;
        exit (0);
    }
    animation->textureL = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);

    surface = IMG_Load(png_right.c_str());
    if (!surface)
    {
        std::cout << "error creating surface 2" << png_right << std::endl;
        exit (0);
    }
    animation->textureR = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}

void        setSize(CS_Animation *animation, float w, float h, float x, float y)
{
    animation->size->w = (w * gameSettings.window_width) / 100.0;
    animation->size->h = (h * gameSettings.window_height) / 100.0;
    animation->size->x = (x * gameSettings.window_width) / 100.0;
    animation->size->y = (y * gameSettings.window_height) / 100.0;
}

void        cutFrame(CS_Animation *animation, int nb_frame, int nb_columnframe, int nb_lineframe)
{
    int i;
    int width;
    int height;
    int frameWidth;
    int frameHeight;

    i = 0;
    SDL_QueryTexture (animation->textureL, NULL, NULL, &width, &height);
    frameWidth = width / nb_columnframe;
    frameHeight = height / nb_lineframe;
    animation->nbFrame = nb_frame;
    animation->nbColumnFrame = nb_columnframe;
    animation->nbLineFrame = nb_lineframe;
    animation->frame.resize(nb_frame);
    while (i < nb_frame)
    {
        animation->frame[i].w = frameWidth;
        animation->frame[i].h = frameHeight;
        animation->frame[i].x = frameWidth * (i % nb_columnframe);
        animation->frame[i].y = frameHeight * (i / nb_columnframe);
        i++;
    }
}

void            setMovement(CS_Animation *animation, int nb_frame, ...)
{
    va_list op;
    int     i;

    i = 0;
    va_start(op, animation, nb_frame);
    animation->movement.resize(nb_frame);
    while (i < nb_frame)
    {
        animation->movement[i] = va_arg(op, int);
        i++;
    }
    va_end(op);
}
