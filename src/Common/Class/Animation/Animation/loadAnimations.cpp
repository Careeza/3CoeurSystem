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
    CS_HitBox   *newHitBox;

    i = 0;
    SDL_QueryTexture (textureL, NULL, NULL, &width, &height);
    frameWidth = width / nb_columnframe;
    frameHeight = height / nb_lineframe;
    nbFrame = nb_frame;
    nbColumnFrame = nb_columnframe;
    nbLineFrame = nb_lineframe;
    frame.resize(nb_frame);
    hitboxes.resize(nb_frame);
    while (i < nb_frame)
    {
        newFrame = new (SDL_Rect);
        newFrame->w = frameWidth;
        newFrame->h = frameHeight;
        newFrame->x = frameWidth * (i % nb_columnframe);
        newFrame->y = frameHeight * (i / nb_columnframe);
        frame[i] = newFrame;

        newHitBox = new (CS_HitBox);
        newHitBox->setWPixel(w);
        newHitBox->setHPixel(h);
        newHitBox->setXPixel(0);
        newHitBox->setYPixel(0);
        hitboxes[i] = newHitBox;
        i++;
    }
}

void        CS_Animation::setSpeed(float speedXSource, float speedYSource)
{
    speedX = Tools->transformWidth(speedXSource);
    speedY = Tools->transformHeight(speedYSource);
}

void            CS_Animation::setSize(float wSource, float hSource)
{
    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);
}

void            CS_Animation::setAnimationTime(int animationTimeSource)
{
    animationTime = animationTimeSource;
    frameTime = animationTimeSource / (float)nbFrame;
}
