# include "gameScene.h"

void    CS_Animation::newAnimation(t_animation nameSource, bool stop)
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
        newFrame->w = frameWidth;
        newFrame->h = frameHeight;
        newFrame->x = frameWidth * (i % nb_columnframe);
        newFrame->y = frameHeight * (i / nb_columnframe);
        frame[i] = newFrame;

        i++;
    }
}

void        CS_Animation::setSpeed(float speedXSource, float speedYSource)
{
    speedX = Tools->transformWidth(speedXSource);
    speedY = Tools->transformHeight(speedYSource);
    std::cout << "speed = " << speedX << " speedSource = " << speedXSource << std::endl;

}

void            CS_Animation::setSize(float wSource, float hSource)
{
    w = Tools->transformWidth(wSource);
    h = Tools->transformHeight(hSource);

    hitboxesR = new (CS_HitBox);
    hitboxesL = new (CS_HitBox);
    attackL = new (CS_HitBox);
    attackR = new (CS_HitBox);

    hitboxesR->setHitBoxPixel(w, h, 0, 0);
    hitboxesL->setHitBoxPixel(w, h, 0, 0);
    attackR->setHitBoxPixel(0, 0, 0, 0);
    attackL->setHitBoxPixel(0, 0, 0, 0);
}

void            CS_Animation::setAnimationTime(int animationTimeSource, int indexStartSource)
{
    animationTime = animationTimeSource;
    frameTime = animationTimeSource / (float)nbFrame;
    indexStart = indexStartSource;
}

void            CS_Animation::setInterrupt(bool interruptSource)
{
    interrupt = interruptSource;
}
