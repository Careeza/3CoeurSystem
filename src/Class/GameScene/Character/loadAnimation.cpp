# include "gameScene.h"

void        setSize(SDL_Rect *size, float w, float h, float x, float y)
{
    size->w = (w * gameSettings.window_width) / 100.0;
    size->h = (h * gameSettings.window_height) / 100.0;
    size->x = (x * gameSettings.window_width) / 100.0;
    size->y = (y * gameSettings.window_height) / 100.0;
}

void        CS_Character::loadAnimation(std::string name)
{
    animation = bank->CS_queryAnimationByname(name);
    setSize(size, 10, 10 * gameSettings.resolution, 45, 50 - (5 * gameSettings.resolution));
    if (animation == NULL)
    {
        std::cout << "we have a prob sir" << std::endl;
        exit (0);
    }
}