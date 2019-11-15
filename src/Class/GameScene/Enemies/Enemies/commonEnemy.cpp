# include "gameScene.h"

CS_CommonEnemy::CS_CommonEnemy()
{
    i = 0;
    std::cout << "i am here" << std::endl;
    bank = new (CS_BankAnimation);
    size = new (SDL_Rect);
    right = true;
}

CS_CommonEnemy::~CS_CommonEnemy()
{
    std::cout << "from here" << std::endl;
    delete bank;
    delete size;
}

SDL_Texture     *CS_CommonEnemy::queryTexture()
{
    return (texture);
}

SDL_Rect        *CS_CommonEnemy::querySize()
{
    return (size);
}

SDL_Rect        *CS_CommonEnemy::queryFrame()
{
    return (frame);
}

void        CS_CommonEnemy::loadAnimation(std::string name)
{
    static CS_Animation *save = NULL;

    std::cout << "i am scooting here" << std::endl;
    animation = bank->CS_queryAnimationByname(name);
    if (save != animation)
    {
        save = animation;
        i = 0;
    }
    if (animation == NULL)
    {
        std::cout << "we have a prob sir" << std::endl;
        exit (0);
    }
}

void        CS_CommonEnemy::setRight(bool rightSource)
{
    right = rightSource;
}


bool        CS_CommonEnemy::useAnimation()
{
    return (CS_UseAnimation(right, animation, size, frame, texture, i));
}