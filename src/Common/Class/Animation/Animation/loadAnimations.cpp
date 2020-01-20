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
    CS_HitBox   *newHitBox;
    CS_HitBox   *newHitBox2;
    CS_HitBox   *newAttack;
    CS_HitBox   *newAttack2;

    i = 0;
    SDL_QueryTexture (textureL, NULL, NULL, &width, &height);
    frameWidth = width / nb_columnframe;
    frameHeight = height / nb_lineframe;
    nbFrame = nb_frame;
    nbColumnFrame = nb_columnframe;
    nbLineFrame = nb_lineframe;
    frame.resize(nb_frame);
    hitboxesR.resize(nb_frame);
    hitboxesL.resize(nb_frame);
    attackR.resize(nb_frame);
    attackL.resize(nb_frame);
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
        hitboxesR[i] = newHitBox;

        newHitBox2 = new (CS_HitBox);
        newHitBox2->setWPixel(w);
        newHitBox2->setHPixel(h);
        newHitBox2->setXPixel(0);
        newHitBox2->setYPixel(0);
        hitboxesL[i] = newHitBox2;

        newAttack = new (CS_HitBox);
        newAttack->setWPixel(w);
        newAttack->setHPixel(h);
        newAttack->setXPixel(0);
        newAttack->setYPixel(0);
        attackR[i] = newAttack;

        newAttack2 = new (CS_HitBox);
        newAttack2->setWPixel(w);
        newAttack2->setHPixel(h);
        newAttack2->setXPixel(0);
        newAttack2->setYPixel(0);
        attackL[i] = newAttack2;
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
