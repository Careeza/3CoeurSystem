# include "gameScene.h"

void    setAnimationSize(float w, float h, float x, float y, SDL_Rect *size)
{
    size->w = (w * gameSettings.window_width) / 100.0;
    size->h = (h * gameSettings.window_height) / 100.0;
    size->x = (x * gameSettings.window_width) / 100.0;
    size->y = (y * gameSettings.window_height) / 100.0;
}

CS_Animation    *loadAnimation(std::string nameSrc, SDL_Renderer *render, std::string png_left, std::string png_right, float w, float h, float x, float y, int nb_frame, int nb_columnframe, int nb_lineframe)
{
    CS_Animation *animation;
    SDL_Surface *surface;
    int         i;

    i = 0;
    animation = new(CS_Animation);
    animation->name = nameSrc;
    setAnimationSize(w, h, x, y, animation->size);
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
        std::cout << "error creating surface 2" << std::endl;
        exit (0);
    }
    animation->textureR = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);

    animation->nbFrame = nb_frame;
    animation->nbColumnFrame = nb_columnframe;
    animation->nbLineFrame = nb_lineframe;

    animation->frame.resize(nb_frame);

    int width;
    int height;
    int frameWidth;
    int frameHeight;

    SDL_QueryTexture (animation->textureL, NULL, NULL, &width, &height);
    frameWidth = width / nb_columnframe;
    frameHeight = height / nb_lineframe;

    while (i < nb_frame)
    {
        animation->frame[i].w = frameWidth;
        animation->frame[i].h = frameHeight;
        animation->frame[i].x = frameWidth * (i % nb_columnframe);
        animation->frame[i].y = frameHeight * (i / nb_lineframe);
        i++;
    }
    return (animation);
}